ATL_FILE_LIST = \
           array.c    double.c  integer.c  long.c    set.c     unit.c \
           char.c     float.c   intset.c   map.c     short.c   void_ast.c \
           complex.c  hash.c    list.c     object.c  string.c  stringbuffer.c \
           bigint.c   multiset.c

ATL_SRCS = $(ATL_FILE_LIST:%.c=atl/%.c)
ATL_OBJS = $(patsubst %.c,%.o,$(ATL_SRCS))

CTESK_SRCS += $(ATL_SRCS)
CTESK_OBJS += $(ATL_OBJS)

#LIB_ATL = lib/linux/libatl.a
#
#LIBS += $(LIB_ATL)
#
#$(LIB_ATL): $(ATL_OBJS)
#	$(AR) $(LIB_ATL) $(ATL_OBJS)
#	ranlib $(LIB_ATL)
