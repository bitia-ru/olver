#!/bin/bash

if [[ -z "$1" || -z "$2" ]]; then
    echo "Using: sh maketags.sh version release"
    exit 1
fi

SPECFILE=olver-$1.xml
ERRNUM=0

rm -f $SPECFILE
touch $SPECFILE

echo '<tags>' >> $SPECFILE

# Header of spec file
echo -n 'Writing header...              '
echo '<summary>OLVER Test Suite</summary>' >> $SPECFILE
echo "<version>$1</version>" >> $SPECFILE
echo "<release>$2</release>" >> $SPECFILE
echo '<license>Apache License Version 2.0</license>' >> $SPECFILE
echo '<group>Development/Tests</group>' >> $SPECFILE
echo '<lsbversion>3.1</lsbversion>' >> $SPECFILE
echo >> $SPECFILE
echo 'OK'

echo -n 'Writing description section... '
if [ ! -f 'description' ]; then
    echo 'FAIL'
    ERRNUM=$((ERRNUM+1))
else
    echo -n '<description>' >> $SPECFILE
    cat description >> $SPECFILE
    echo '</description>' >> $SPECFILE
    echo 'OK'
    echo >> $SPECFILE
fi

echo -n 'Writing pre section...         '
if [ ! -f 'pre' ]; then
    echo 'FAIL'
    ERRNUM=$((ERRNUM+1))
else
    echo -n '<pre>' >> $SPECFILE
    echo >> $SPECFILE
    cat pre >> $SPECFILE
    echo >> $SPECFILE
    echo '</pre>' >> $SPECFILE
    echo 'OK'
    echo >> $SPECFILE
fi

echo -n 'Writing preun section...       '
if [ ! -f 'preun' ]; then
    echo 'FAIL'
    ERRNUM=$((ERRNUM+1))
else
    echo -n '<preun>' >> $SPECFILE
    echo >> $SPECFILE
    cat preun >> $SPECFILE
    echo >> $SPECFILE
    echo '</preun>' >> $SPECFILE
    echo 'OK'
    echo >> $SPECFILE
fi

echo -n 'Writing post section...        '
if [ ! -f 'post' ]; then
    echo 'FAIL'
    ERRNUM=$((ERRNUM+1))
else
    echo -n '<post>' >> $SPECFILE
    echo >> $SPECFILE
    cat post >> $SPECFILE
    echo >> $SPECFILE
    echo '</post>' >> $SPECFILE
    echo 'OK'
    echo >> $SPECFILE
fi

echo -n 'Writing postun section...      '
if [ ! -f 'postun' ]; then
    echo 'FAIL'
    ERRNUM=$((ERRNUM+1))
else
    echo -n '<postun>' >> $SPECFILE
    echo >> $SPECFILE
    cat postun >> $SPECFILE
    echo >> $SPECFILE
    echo '</postun>' >> $SPECFILE
    echo 'OK'
    echo >> $SPECFILE
fi

echo '</tags>' >> $SPECFILE

echo
if [ $ERRNUM == 0 ]; then
    echo 'Done'
    exit 0
else
    echo 'Fail'
    exit $ERRNUM
fi