NETDB_SOURCES =



SOURCES += $(NETDB_SOURCES:%.c=socket/netdb/%.c)
SOURCES += $(wildcard socket/netdb/*_config.c)
SEC_SOURCES += $(wildcard socket/netdb/*.sec)

include socket/netdb/tests/Makefile

