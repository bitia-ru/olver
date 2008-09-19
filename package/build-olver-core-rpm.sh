#!/bin/bash

if [[ -z $1 || -z $2 ]]; then
    echo "Using: sh build-olver-core-rpm.sh version release"
    exit 1
fi

# Adjust Directory
DEST=`pwd`
pushd ${0%/*} > /dev/null 2>&1

# Building sources
../build_conf_tests.sh -r

# Configure
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
sed "s/^\s*global\.TARGET_DATA_TYPES_ARCH\s.*$/global\.TARGET_DATA_TYPES_ARCH = LSB_ARCH_${ARCH}/" -i ../etc/olver.conf > /dev/null
sed 's/^\s*global\.TEST_DATA_PATH\s.*$/global\.TEST_DATA_PATH = \/opt\/lsb\/test\/olver-core\/testdata/' -i ../etc/olver.conf > /dev/null 2>&1
sed 's/^\s*global\.USER_NAME_TESTER\s.*$/global\.USER_NAME_TESTER = olver_tester/' -i ../etc/olver.conf > /dev/null 2>&1

# Building rpm
../tools/buildrpm/buildrpm.sh $1 $2
mv -f ../tools/buildrpm/lsb-test-olver-core-*.rpm $DEST

popd > /dev/null 2>&1
exit 0
