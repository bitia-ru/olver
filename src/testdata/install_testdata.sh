DIR=${0%/*}
cd $DIR

echo -n "Installing test data for locale.nlcat ...      "
pushd locale.nlcat>/dev/null 2>&1
gencat -o catfirst.cat catfirst.msg
gencat -o catsecond.cat catsecond.msg
gencat -o catthird.cat catthird.msg
popd>/dev/null 2>&1
echo 'Done'

echo -n "Installing test data for locale.textdomain ... "
pushd locale.textdomain>/dev/null 2>&1
find . -name '*.po'>makefile 2>/dev/null
sed -r 's/(.+).po/msgfmt \1.po -o \1.mo/' makefile -i
chmod +x makefile
./makefile
rm -f makefile
popd>/dev/null 2>&1
echo 'Done'
