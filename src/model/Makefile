MODULES = common\
	config\
	core\
	data\
	fs\
	io\
	memory\
	process\
	pthread\
	system\
	util\
	math\
	locale\
	signal\
	socket\
	time\
	ncurses

include $(MODULES:%=%/Makefile)

###########################################################
# Parameters of compilation
###########################################################
CC      = gcc
LD      = g++
SEC         = "$(CTESK_HOME)/bin/massive-sec.sh"
SECPP       = "$(CTESK_HOME)/bin/sec-pp.sh"
LIBTYPE     = gcc
CTESK_LIBPATH   = $(CTESK_HOME)/lib/$(LIBTYPE)

CFLAGS = -g -std=c99 -D_POSIX_C_SOURCE=200112L $(INCLUDE) -I. "-I$(CTESK_HOME)/include"
LIB = $(XLIB) -g -Wl,--relax -rdynamic "-L$(CTESK_LIBPATH)" "-L." -lctesk -lstdc++ -lpthread
LDFLAGS = $(LIB)

DEPENDS = $(patsubst %.sec,%.d,$(SEC_SOURCES))

SEC_C_SOURCES = $(patsubst %.sec,%.c,$(SEC_SOURCES))
SEI_SOURCES = $(patsubst %.sec,%.sei,$(SEC_SOURCES))

SEI_DEPENDS = $(patsubst %.sec,%.sd,$(SEC_SOURCES))

C_OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
SEC_C_OBJECTS = $(patsubst %.c,%.o,$(SEC_C_SOURCES))

OLVER=../../bin/olver


###########################################################
# Main goals
###########################################################

all: $(OLVER)
	@echo Build completed

$(DEPENDS):%.d:
	@set -e; $(CC) $(CFLAGS) -xc -MM -MT $(*F).sei $*.sec > $@
	@echo "$*.d $(*D)/`cat $@`" > $@

ifndef SKIP_SEC
-include $(DEPENDS)
endif

$(OLVER): $(C_OBJECTS) $(SEC_C_OBJECTS)
	@echo "Linking..."
	@$(LD) $(C_OBJECTS) $(SEC_C_OBJECTS) -o $(OLVER) $(LDFLAGS)

clean:
	-rm -f $(C_OBJECTS)
	-rm -f $(SEC_C_OBJECTS)
	-rm -f $(SEC_C_SOURCES)
	-rm -f $(SEI_SOURCES)
	-rm -f $(DEPENDS)
	-rm -f $(SEI_DEPENDS)
	-rm -f $(OLVER)

olver_dc: $(OLVER_DC_SOURCES:%.c=%.o)
	$(LD) $(OLVER_DC_SOURCES:%.c=%.o) -o $@


###########################################################
# Translation rules
###########################################################
$(C_OBJECTS) $(SEC_C_OBJECTS):%.o: %.c
	@echo Compiling $*.c
	@$(CC) $(CFLAGS) "-I$(@D)" -c $*.c -o $*.o

$(SEC_C_SOURCES):%.c: $(SEI_DEPENDS)
	@if test -f sec2c.cmd; then $(SEC) @sec2c.cmd generate; rm -f sec2c.cmd >/dev/null 2>&1; fi

$(SEI_DEPENDS):%.sd: %.sei
	@if test $*.sei -nt $*.c; then echo $*.sei >> sec2c.cmd; fi

$(SEI_SOURCES):%.sei: %.sec
	@echo Translating file $<...
	@$(SECPP) $*.sec -o $*.sei $(CFLAGS) "-I$(@D)"

.PHONY: all clean
