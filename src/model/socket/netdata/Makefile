NETDATA_SOURCES =



SOURCES += $(NETDATA_SOURCES:%.c=socket/netdata/%.c)
SOURCES += $(wildcard socket/netdata/*_config.c)
SEC_SOURCES += $(wildcard socket/netdata/*.sec)

include socket/netdata/tests/Makefile

