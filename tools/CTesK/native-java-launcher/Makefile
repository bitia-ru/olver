SHELL=/bin/bash
CC=lsbcc
SRCS=src/launcher.c src/config.c src/config.h
OBJS=src/launcher.o src/config.o

all: launcher

launcher: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS): $(SRCS)

clean: 
	rm -f $(OBJS)
	rm -f launcher
