#!/bin/bash

if [[ -z $1 || -z $2 ]]; then
    echo "Using: sh buildrpm.sh version release"
    exit 1
fi

#
# Adjust Directory
#
pushd ${0%/*} > /dev/null 2>&1

rm -rf olver-$1-$2
mkdir -p olver-$1-$2/opt/lsb/test/olver-core
cd olver-$1-$2/opt/lsb/test/olver-core

OLVERPWD=../../../../../../..

#
# Binary section
#
mkdir bin
mkdir bin/terminfo
mkdir -p ../../../../usr/share/terminfo/o

cp -f $OLVERPWD/bin/olver bin/olver
cp -f $OLVERPWD/bin/agent bin/agent
cp -f $OLVERPWD/bin/olverterm bin/olverterm
cp -f $OLVERPWD/bin/terminfo/olverct.terminfo bin/terminfo/olverct.terminfo
cp -f $OLVERPWD/bin/terminfo/o/olverct ../../../../usr/share/terminfo/o/olverct

cp -f $OLVERPWD/bin/olver_run_tests bin/olver_run_tests
cp -f $OLVERPWD/bin/olver_pre bin/olver_pre
cp -f $OLVERPWD/bin/olver_report bin/olver_report
cp -f $OLVERPWD/bin/testplan bin/testplan
cp -f $OLVERPWD/bin/ask_root.sh bin/ask_root.sh

#
# Configuration section
#
mkdir etc
cp -f $OLVERPWD/etc/olver.conf etc/ > /dev/null 2>&1
cp -f $OLVERPWD/etc/times.ref etc/ > /dev/null 2>&1

#
# Tools section
#
mkdir tools
mkdir tools/BugDB
mkdir tools/TraceTools
mkdir tools/reportgen
mkdir tools/share
cp -f $OLVERPWD/tools/BugDB/BugDB.xml tools/BugDB/BugDB.xml
cp -f $OLVERPWD/tools/BugDB/Readme.doc tools/BugDB/Readme.doc
cp -rf $OLVERPWD/tools/TraceTools/* tools/TraceTools/
cp -rf $OLVERPWD/tools/reportgen/* tools/reportgen/
cp -rf $OLVERPWD/tools/share/* tools/share/

#
# Testdata section
#
mkdir testdata

cp -f $OLVERPWD/src/testdata/install_testdata.sh testdata/
cp -rf $OLVERPWD/src/testdata/math.exp testdata/
cp -rf $OLVERPWD/src/testdata/math.trig testdata/
cp -rf $OLVERPWD/src/testdata/math.bessel testdata/

mkdir -p testdata/util.dl
cp -f $OLVERPWD/src/testdata/util.dl/libmy.so testdata/util.dl

mkdir -p testdata/locale.textdomain/Path1/en_US/LC_MESSAGES
cp -f $OLVERPWD/src/testdata/locale.textdomain/Path1/en_US/LC_MESSAGES/testdomain.po testdata/locale.textdomain/Path1/en_US/LC_MESSAGES

mkdir -p testdata/locale.textdomain/Path2/en_US/LC_MESSAGES
cp -f $OLVERPWD/src/testdata/locale.textdomain/Path2/en_US/LC_MESSAGES/anotherdomain.po testdata/locale.textdomain/Path2/en_US/LC_MESSAGES

mkdir testdata/locale.nlcat
find $OLVERPWD/src/testdata/locale.nlcat -name '*.msg' -exec cp -f '{}' testdata/locale.nlcat/ \;>/dev/null 2>&1

#
# Document section
#
mkdir doc
cp -rf $OLVERPWD/doc/* doc/

#
# CVS clean
#
find . -name "CVS" -type d -exec rm -rf '{}' \; > /dev/null 2>&1

cd ../../../../..

echo
echo 'Building the specification file...'
./maketags.sh $1 $2

if [ ! $? = 0 ]; then
    popd > /dev/null 2>&1
    exit 1
fi

RES=0

echo
echo 'Building the package...'
/opt/lsb/bin/makelsbpkg --verbose --tagfile=olver-$1.xml lsb-test-olver-core olver-$1-$2

if [ ! $? = 0 ]; then
    RES=$?
fi

rm -rf olver-$1-$2
rm -f olver-$1.xml

echo

if [ ! $RES = 0 ]; then
    echo 'Fail'
    popd > /dev/null 2>&1
    exit 1
fi

echo 'Done'
popd > /dev/null 2>&1
