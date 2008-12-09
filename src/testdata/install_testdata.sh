DIR=${0%/*}
cd $DIR

echo -n "Installing test data for locale.nlcat ...      "
cd locale.nlcat
gencat -o catfirst.cat catfirst.msg
gencat -o catsecond.cat catsecond.msg
gencat -o catthird.cat catthird.msg
cd ..
echo 'Done'

echo -n "Installing test data for locale.textdomain ... "
cd locale.textdomain
find . -name '*.po'>genmo 2>/dev/null
sed -r 's/(.+).po/msgfmt \1.po -o \1.mo/' genmo -i
chmod +x genmo
./genmo
rm -f genmo
cd ..
echo 'Done'

