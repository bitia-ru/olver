#!/bin/bash
#
# This script builds the test data
#

code=0

echo -n "Building test data for util.dl ...             "
cd util.dl
make
((code+=$?))
cd ..

./install_testdata.sh

exit $code
