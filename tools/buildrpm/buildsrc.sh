#!/bin/bash

if [[ -z $1 || -z $2 || -z $3 ]]; then
    echo "Using: sh buildsrc.sh olver_dir version release"
    exit 1
elif [ ! -d $1 ]; then
    echo "Error: no such directory: $1"
    exit 1
elif [ ! -f $1/build_conf_tests.sh ]; then
    echo "Error: not an olver root directory: $1"
    exit 1
fi

#
# Adjust Directory
#
DEST=`pwd`
SOURCE=`cd $1 && pwd`
SRC_DIR=olver-core

rm -rf $SRC_DIR
mkdir -p $SRC_DIR
pushd $SRC_DIR &> /dev/null

#
# Package section
#
mkdir package
cp -f $SOURCE/package/Makefile package/Makefile
cp -f $SOURCE/package/HOWTO package/HOWTO

#
# Build section
#
cp -f $SOURCE/build_conf_tests.sh ./build_conf_tests.sh
cp -f $SOURCE/build_prerequisites.sh ./build_prerequisites.sh
cp -f $SOURCE/agent_perm.sh ./agent_perm.sh

#
# Binary section
#
mkdir bin

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
sed 's/^\s*global\.TEST_DATA_PATH\s.*$/global\.TEST_DATA_PATH = \/opt\/lsb\/test\/olver-core\/testdata/' -i etc/olver.conf &> /dev/null
sed 's/^\s*global\.USER_NAME_TESTER\s.*$/global\.USER_NAME_TESTER = olver_tester/' -i etc/olver.conf &> /dev/null

#
# Source section
#
mkdir -p src
mkdir -p config

cp -rf $SOURCE/src/* src/
cp -rf $SOURCE/config/* config/

#
# Tools section
#
mkdir tools
mkdir tools/BugDB
mkdir tools/TraceTools
mkdir tools/reportgen
mkdir tools/share
mkdir tools/CTesK
mkdir tools/buildrpm
cp -rf $SOURCE/tools/BugDB/* tools/BugDB/
cp -rf $SOURCE/tools/TraceTools/* tools/TraceTools/
cp -rf $SOURCE/tools/reportgen/* tools/reportgen/
cp -rf $SOURCE/tools/share/* tools/share/
cp -rf $SOURCE/tools/CTesK/* tools/CTesK/
cp -f $SOURCE/tools/buildrpm/* ./tools/buildrpm/ &> /dev/null

#
# Documentation section
#
mkdir doc
cp -rf $SOURCE/doc/* doc/

#
# CVS clean
#
find . -name "CVS" -type d -exec rm -rf '{}' \; > /dev/null 2>&1
find . -name ".cvsignore" -type f -exec rm -f '{}' \; &> /dev/null

#
# Permissions
#
find . -type d -exec chmod 775 '{}' \; &> /dev/null
find . -type f -exec chmod 664 '{}' \; &> /dev/null
find . -name '*.sh' -exec chmod 775 '{}' \; &> /dev/null
find . -name '*.pl' -exec chmod 775 '{}' \; &> /dev/null
find . -name '*.exe' -exec chmod 775 '{}' \; &> /dev/null
find . -name '*.bat' -exec chmod 775 '{}' \; &> /dev/null
find . -type f -path './bin/*' -name 'olver*' ! -name 'testplan' -exec chmod 775 '{}' \; &> /dev/null
find . -name 'tjreport' -exec chmod 775 '{}' \; &> /dev/null
find . -name 'install-sh' -exec chmod 775 '{}' \; &> /dev/null

popd &> /dev/null

tar cz --remove-files -f lsb-test-olver-core-$2-$3.tar.gz ./olver-core
exit 0
