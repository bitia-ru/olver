#!/bin/bash
#
#

DIR=${0%/*}
cd $DIR

echo -n "Uninstalling test data for locale.nlcat ...      "
cd locale.nlcat
rm -f catfirst.cat
rm -f catsecond.cat
rm -f catthird.cat
cd ..
echo 'Done'

echo -n "Uninstalling test data for locale.textdomain ... "
cd locale.textdomain
find . -name '*.mo' -exec rm -f '{}' \; 2>/dev/null
cd ..
echo 'Done'
