###########################################################
# Default goal
###########################################################
default_goal: all

###########################################################
# Parameters of compilation
###########################################################

CC = gcc

CFLAGS = -std=c99 -D_POSIX_C_SOURCE=200112L -D_XOPEN_SOURCE=600 -g -I ../../lsb/include -I.
LIB = $(XLIB) -lpthread -lrt -lutil -lm -lcrypt -lz -lpam -ldl -lncurses -L. -lolverterm
LDFLAGS = $(LIB)

###########################################################
# Main goals
###########################################################
all: libmy.so
	@echo Build completed

libmy.so: lib.c
	gcc lib.c -fPIC -shared -o libmy.so

clean:
	@-rm -f libmy.so

.PHONY: all clean
