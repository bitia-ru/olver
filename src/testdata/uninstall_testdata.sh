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

echo -n "Uninstalling Olver-locale for locale.locale ...  "
localedef --delete-from-archive Olver_Locale > /dev/null 2>&1
localedef --delete-from-archive Olver_Locale.ansix341968 > /dev/null 2>&1
echo 'Done'

