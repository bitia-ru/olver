#!/bin/bash
tic dep/olverct.terminfo
export ALLFLAGS="-g -D_XOPEN_SOURCE=500 -D_XOPEN_SOURCE_EXTENDED -D_CURSES_HEADER="\"curses.h\"" -I../../lsb/include"
echo $ALLFLAGS
#libolverterm.a
gcc -c communicate.c $ALLFLAGS -o communicate.o
gcc -c socket.c $ALLFLAGS -o socket.o
echo Creating libolverterm.a
ar cr libolverterm.a communicate.o socket.o
rm *.o

mv libolverterm.a ../agent

if test -z "$1"
then
echo "Skipping olverterm build"
else
#olverterm
echo "Building olverterm"

#libiterm.a:
if  [ ! -e "libiterm.a" ]
then
    cd ./lib/
    ./get_libiterm.sh
    make clean
    cd ..
fi

gcc $ALLFLAGS dump.c itp_opts.c memterm.c tools.c vt.c ../agent/libolverterm.a libiterm.a -lcurses -o olverterm
mv olverterm ../agent
fi

#echo Building test program
#gcc $ALLFLAGS memterm_prog.c -literm -lcurses libolverterm.a -o memterm_prog

#export CT_SOCKNAME=olversock
#export TEST_NAME="memterm_prog"
#export TERM_DUMP="${TEST_NAME}.termdump"
#export TERM_EXP="${TEST_NAME}.termexp"
#export TERM_DIFF="${TEST_NAME}.termdiff"
#export CT_DUMPFILE="${TEST_NAME}.progdump"

#export TERM_SIZE="20x40"

#echo Executing test
#echo ./olverterm -g ${TERM_SIZE} -t olverct -e "./${TEST_NAME}" -o ${TERM_DUMP}
#./olverterm -g ${TERM_SIZE} -t olverct -e "./${TEST_NAME}" -o ${TERM_DUMP}
exit

