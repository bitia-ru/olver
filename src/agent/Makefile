MODULES = common \
          fs \
          io \
          locale \
          math \
          memory \
          ncurses \
          process \
          pthread \
          signal \
          socket \
          system \
          time \
          util


###########################################################
# Default goal
###########################################################
default_goal: all


###########################################################
# Modules
###########################################################
HOSTTYPE := $(shell uname -i)
include $(MODULES:%=%/Makefile)


###########################################################
# Parameters of compilation
###########################################################

SHELL = /bin/bash
#CC = gcc
CC = lsbcc

CFLAGS = -std=c99 -D_POSIX_C_SOURCE=200112L -D_XOPEN_SOURCE=600 -g -I /opt/lsb/include -I.
LIB = $(XLIB) -lpthread -lrt -lutil -lm -lcrypt -lz -lpam -ldl -lncurses -L. -lolverterm
LDFLAGS = $(LIB)
MAKEAR= ar r

AGENT=../../bin/agent
OLVERTERM=../../bin/olverterm

###########################################################
# Main goals
###########################################################
all: $(AGENT)
	@echo Build completed 


$(AGENT): $(SOURCES:%.c=%.o) $(AGENT_LIBRARIES) $(OLVERTERM) libolverterm.a miss.o
	$(CC) $(SOURCES:%.c=%.o) $(AGENT_LIBRARIES) -o $(AGENT) $(LDFLAGS) miss.o

miss.o: miss.c

#miss.c:
#	echo "int ____empty____;" > miss.c

$(OLVERTERM):
	pushd ../olverterm/; make all; popd

libolverterm.a:
	pushd ../olverterm/; make all; popd

OBJS := $(filter %.c,$(SOURCES))
OBJS := $(OBJS:%.c=%.o)

clean: $(CLEAN_MODULES)
	-rm -f $(OBJS)
	-rm -f $(AGENT)
	-rm -f olverterm libolverterm.a
	-pushd ../olverterm/; make clean; popd

olver_daemon: common/libagent.a $(OLVER_DAEMON_SOURCES:%.c=%.o)
	$(CC) $(OLVER_DAEMON_SOURCES:%.c=%.o) $(AGENT_LIBRARIES) -o $@ -lpthread -lrt

###########################################################
# Translation rules
###########################################################
%.o: %.c
	@ $(CC) $(CFLAGS) `echo $< | awk -F'/' '{for(i=1; i<=NF-1;i++) {printf(" -I");for (j=1; j<= i; j++) printf("%s/", $$j);}} '` -c $< -o $@

.PHONY: all clean

