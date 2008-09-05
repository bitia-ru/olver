#!/bin/bash

if [[ -z $1 || -z $2 ]]; then
    echo "Using: sh buildrpm.sh version release"
    exit 1
fi

# Adjust Directory
DEST=`pwd`
pushd ${0%/*} > /dev/null 2>&1

# Configure
ARCH=`uname -m`

if [ ${ARCH#i?} = 86 ]; then
    ARCH=i486
fi
echo "OLVER was configured for $ARCH architecture"
cp -f ../etc/olver_$ARCH.conf ../etc/olver.conf

# Building sources
../build_conf_tests.sh

# Building rpm
../tools/buildrpm/buildrpm.sh $1 $2
cp -f ../tools/buildrpm/lsb-test-olver-core-*.rpm $DEST

popd > /dev/null 2>&1
