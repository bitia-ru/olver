#echo Building test program

cp ../agent/olverterm .
cp ../agent/libolverterm.a .

export ALLFLAGS="-D_XOPEN_SOURCE=500 -D_XOPEN_SOURCE_EXTENDED -I../../lsb/include" -D_CURSES_HEADER="\"curses.h\""

gcc -std=c99 $ALLFLAGS memterm_prog.c -literm -lncurses libolverterm.a -ldl -o mm

export CT_SOCKNAME=olversock
export TEST_NAME="mm"
export TERM_DUMP="${TEST_NAME}.termdump"
export TERM_EXP="${TEST_NAME}.termexp"
export TERM_DIFF="${TEST_NAME}.termdiff"
export CT_DUMPFILE="${TEST_NAME}.progdump"
export TERMINFO="./dep"

export TERM_SIZE="80x25"

echo Executing test
echo ./olverterm -g ${TERM_SIZE} -t olverct -e "./${TEST_NAME}" -o ${TERM_DUMP}
./olverterm -g ${TERM_SIZE} -t olverct -e "./${TEST_NAME}" -o ${TERM_DUMP}
echo $?
echo "Progdump:"
cat mm.progdump
echo "Termdump:"
cat mm.termdump

rm -f mm.progdump
rm -f mm.termdump
