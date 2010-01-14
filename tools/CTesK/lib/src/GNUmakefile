MODULES = utils c_tracer atl ts

include $(MODULES:%=%/GNUmakefile)

DEBUG 		= -g3
RELEASE 	= -O
INCLUDE		= -I /opt/lsb/include -I.
CC		= lsbcc
# CPP		= g++
#LD		= g++
LD		= lsbcc
AR		= ar r

CFLAGS 		= $(INCLUDE) $(DEBUG) $(RELEASE)
# CPPFLAGS	= $(INCLUDE) $(DEBUG) $(RELEASE) -DATL_CLONE_DISABLE
LDFLAGS		= $(DEBUG)

LIBCTESK	= libctesk.a

RM		= rm -rf

C_DEPENDS 	= $(patsubst %.c,%.d,$(CTESK_SRCS))
# CPP_DEPENDS = $(patsubst %.cpp,%.d,$(CTESK_CPP_SRCS))

all: $(LIBCTESK)

$(LIBCTESK): $(CTESK_OBJS)
	$(AR) $@ $(CTESK_OBJS)
	ranlib $@

-include $(C_DEPENDS)
# include $(CPP_DEPENDS)

$(C_DEPENDS):%.d:
	@set -e; $(CC) -MM $(CFLAGS) $*.c > $@
	@echo "$*.d $(*D)/`cat $@`" > $@

#$(CPP_DEPENDS):%.d:
#	@set -e; $(CPP) -MM $(CPPFLAGS) $*.cpp > $@
#	@echo "$*.d $(*D)/`cat $@`" > $@

clean:
	$(RM) $(CTESK_OBJS) $(C_DEPENDS)
#	$(RM) $(CTESK_OBJS) $(C_DEPENDS) $(CPP_DEPENDS)
	$(RM) $(LIBCTESK)

.SUFFIXES: .o .c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#%.o: %.cpp
#	$(CPP) $(CPPFLAGS) -c $< -o $@
