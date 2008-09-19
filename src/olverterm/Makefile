###########################################################
# Default goal
###########################################################
default_goal: all

###########################################################
# Parameters of compilation
###########################################################
DIR = ./lib

CC = lsbcc
CFLAGS = -g -D_XOPEN_SOURCE=500 -D_XOPEN_SOURCE_EXTENDED -D_CURSES_HEADER="\"curses.h\"" -I/opt/lsb/include -I$(DIR)/include
LIB = -lncurses
CFILES = dump.c itp_opts.c memterm.c tools.c vt.c

OLVERTERM=../../bin/olverterm

###########################################################
# Main goals
###########################################################
all: $(OLVERTERM)
	@echo Build completed

communicate.o: communicate.c
	$(CC) -c communicate.c $(CFLAGS) -o communicate.o

socket.o: socket.c
	$(CC) -c socket.c $(CFLAGS) -o socket.o

../agent/libolverterm.a: communicate.o socket.o
	echo Creating libolverterm.a
	ar cr libolverterm.a communicate.o socket.o
	rm *.o
	mv libolverterm.a ../agent

libiterm.a:
	find $(DIR) -name *.am -exec touch {} \;
	pushd $(DIR); aclocal; autoreconf -f -i; ./configure; make; cp ./src/.libs/libiterm.a ../libiterm.a; popd

$(OLVERTERM): $(CFILES) ../agent/libolverterm.a libiterm.a
	echo "Building olverterm"
	$(CC) $(CFLAGS) $(CFILES) ../agent/libolverterm.a libiterm.a $(LIB) -o $(OLVERTERM)

clean:
	pushd $(DIR); make clean; popd
	rm -rf libiterm.a
	rm -rf ../agent/libolverterm.a
	rm -rf $(OLVERTERM)
###########################################################
# Translation rules
###########################################################
.PHONY: all clean
