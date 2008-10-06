#!/bin/bash

if [[ -z $1 || -z $2 || -z $3 ]]; then
    echo "Using: sh buildrpm.sh olver_dir version release"
    exit 1
elif [ ! -d $1 ]; then
    echo "No such directory: $1"
    exit 1
fi

#
# Adjust Directory
#
DEST=`pwd`
SOURCE=`cd $1 && pwd`
PACKAGE_DIR=olver-core-package

rm -rf $PACKAGE_DIR
mkdir -p $PACKAGE_DIR/opt/lsb/test/olver-core
pushd $PACKAGE_DIR/opt/lsb/test/olver-core >/dev/null 2>/dev/null

#
# Binary section
#
mkdir bin
mkdir bin/terminfo
mkdir -p ../../../../usr/share/terminfo/o

cp -f $SOURCE/bin/olver bin/olver
cp -f $SOURCE/bin/agent bin/agent
cp -f $SOURCE/bin/olverterm bin/olverterm
cp -f $SOURCE/bin/terminfo/olverct.terminfo bin/terminfo/olverct.terminfo
cp -f $SOURCE/bin/terminfo/o/olverct ../../../../usr/share/terminfo/o/olverct

cp -f $SOURCE/bin/olver_run_tests bin/olver_run_tests
cp -f $SOURCE/bin/olver_pre bin/olver_pre
cp -f $SOURCE/bin/olver_report bin/olver_report
cp -f $SOURCE/bin/testplan bin/testplan

#
# Configuration section
#
mkdir etc
cp -f $SOURCE/etc/olver.conf etc/
cp -f $SOURCE/etc/times.ref etc/

ARCH=`uname -m`
if [ ${ARCH#i?} = 86 ]; then
    ARCH=i486
fi
echo "OLVER was configured for $ARCH architecture"

ARCH=`uname -m | tr '[:lower:]' '[:upper:]'`
if [ ${ARCH#I?} = 86 ]; then
    ARCH=IA32
fi
if [ ${ARCH} = X86_64 ]; then
    ARCH=AMD64
fi
if [ ${ARCH} = PPC ]; then
    ARCH=PPC32
fi
sed "s/^\s*global\.TARGET_DATA_TYPES_ARCH\s.*$/global\.TARGET_DATA_TYPES_ARCH = LSB_ARCH_${ARCH}/" -i ./etc/olver.conf >/dev/null 2>/dev/null
sed 's/^\s*global\.TEST_DATA_PATH\s.*$/global\.TEST_DATA_PATH = \/opt\/lsb\/test\/olver-core\/testdata/' -i ./etc/olver.conf >/dev/null 2>/dev/null
sed 's/^\s*global\.USER_NAME_TESTER\s.*$/global\.USER_NAME_TESTER = olver_tester/' -i ./etc/olver.conf >/dev/null 2>/dev/null

#
# Tools section
#
mkdir tools
mkdir tools/BugDB
mkdir tools/TraceTools
mkdir tools/reportgen
mkdir tools/share
cp -f $SOURCE/tools/BugDB/BugDB.xml tools/BugDB/BugDB.xml
cp -f $SOURCE/tools/BugDB/Readme.doc tools/BugDB/Readme.doc
cp -rf $SOURCE/tools/TraceTools/* tools/TraceTools/
cp -rf $SOURCE/tools/reportgen/* tools/reportgen/
cp -rf $SOURCE/tools/share/* tools/share/

#
# Testdata section
#
mkdir -p testdata

cp -f $SOURCE/src/testdata/install_testdata.sh testdata/
cp -f $SOURCE/src/testdata/uninstall_testdata.sh testdata/
cp -rf $SOURCE/src/testdata/math.exp testdata/
cp -rf $SOURCE/src/testdata/math.trig testdata/
cp -rf $SOURCE/src/testdata/math.bessel testdata/

mkdir -p testdata/util.dl
cp -f $SOURCE/src/testdata/util.dl/libmy.so testdata/util.dl

mkdir -p testdata/locale.textdomain/Path1/en_US/LC_MESSAGES
cp -f $SOURCE/src/testdata/locale.textdomain/Path1/en_US/LC_MESSAGES/testdomain.po testdata/locale.textdomain/Path1/en_US/LC_MESSAGES

mkdir -p testdata/locale.textdomain/Path2/en_US/LC_MESSAGES
cp -f $SOURCE/src/testdata/locale.textdomain/Path2/en_US/LC_MESSAGES/anotherdomain.po testdata/locale.textdomain/Path2/en_US/LC_MESSAGES

mkdir testdata/locale.nlcat
find $SOURCE/src/testdata/locale.nlcat -name '*.msg' -exec cp -f '{}' testdata/locale.nlcat/ \; >/dev/null 2>/dev/null

#
# Document section
#
mkdir doc
cp -rf $SOURCE/doc/* doc/

#
# CVS clean
#
find . -name "CVS" -type d -exec rm -rf '{}' \; >/dev/null 2>/dev/null
find . -name ".cvsignore" -type f -exec rm -f '{}' \; >/dev/null 2>/dev/null

popd >/dev/null 2>/dev/null

#
# RPM building
#
echo
echo 'Building the specification file...'
pushd ${0%/*} >/dev/null 2>/dev/null
./maketags.sh $2 $3
if [ ! $? = 0 ]; then
    exit 1
fi
mv -f olver-$2.xml $DEST/
popd >/dev/null 2>/dev/null

RES=1
echo
echo 'Building the package...'
/opt/lsb/bin/fakeroot /bin/bash <<FAKEROOT
chown -R root:root $PACKAGE_DIR
/opt/lsb/bin/makelsbpkg --verbose --tagfile=./olver-$2.xml lsb-test-olver-core $PACKAGE_DIR
exit $?
FAKEROOT
RES=$?

rm -rf $PACKAGE_DIR
rm -f olver-$2.xml

if [ ! $RES = 0 ]; then
    echo 'Failed'
    exit 1
else
    echo 'Done'
    exit 0
fi
