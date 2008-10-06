DIR=${0%/*}
cd $DIR

echo -n "Uninstalling test data for locale.nlcat ...      "
pushd locale.nlcat>/dev/null 2>&1
rm -f catfirst.cat
rm -f catsecond.cat
rm -f catthird.cat
popd>/dev/null 2>&1
echo 'Done'

echo -n "Uninstalling test data for locale.textdomain ... "
pushd locale.textdomain>/dev/null 2>&1
find . -name '*.mo' -exec rm -f '{}' \; 2>/dev/null
popd>/dev/null 2>&1
echo 'Done'
