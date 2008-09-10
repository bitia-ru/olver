#!/bin/bash

if [[ -z $1 || -z $2 ]]; then
    echo "Using: sh buildsrc.sh version release"
    exit 1
fi

#
# Adjust Directory
#
pushd ${0%/*} > /dev/null 2>&1

rm -rf olver-core
mkdir -p olver-core
cd olver-core

OLVERPWD=../../..

#
# Package section
#
mkdir package
cp -f $OLVERPWD/package/build-olver-core-rpm.sh package/build-olver-core-rpm.sh
cp -f $OLVERPWD/package/HOWTO package/HOWTO

#
# Build section
#
cp -f $OLVERPWD/build_conf_tests.sh ./build_conf_tests.sh
cp -f $OLVERPWD/build_prerequisites.sh ./build_prerequisites.sh
cp -f $OLVERPWD/agent_perm.sh ./agent_perm.sh

#
# Binary section
#
mkdir bin

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
sed 's/^\s*global\.TEST_DATA_PATH\s.*$/global\.TEST_DATA_PATH = \/opt\/lsb\/test\/olver-core\/testdata/' -i etc/olver.conf > /dev/null 2>&1
sed 's/^\s*global\.USER_NAME_TESTER\s.*$/global\.USER_NAME_TESTER = olver_tester/' -i etc/olver.conf > /dev/null 2>&1

#
# Source section
#
mkdir -p src
mkdir -p config

cp -rf $OLVERPWD/src/* src/
cp -rf $OLVERPWD/config/* config/

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
cp -rf $OLVERPWD/tools/BugDB/* tools/BugDB/
cp -rf $OLVERPWD/tools/TraceTools/* tools/TraceTools/
cp -rf $OLVERPWD/tools/reportgen/* tools/reportgen/
cp -rf $OLVERPWD/tools/share/* tools/share/
cp -rf $OLVERPWD/tools/CTesK/* tools/CTesK/
cp -f $OLVERPWD/tools/buildrpm/* ./tools/buildrpm/

#
# Documentation section
#
mkdir doc
cp -rf $OLVERPWD/doc/* doc/

#
# CVS clean
#
find . -name "CVS" -type d -exec rm -rf '{}' \; > /dev/null 2>&1

cd ..
tar cz --remove-files -f lsb-test-olver-core-$1-$2.tar.gz ./olver-core
popd > /dev/null 2>&1
