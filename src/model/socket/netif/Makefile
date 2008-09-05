NETIF_SOURCES =



SOURCES += $(NETIF_SOURCES:%.c=socket/netif/%.c)
SOURCES += $(wildcard socket/netif/*_config.c)
SEC_SOURCES += $(wildcard socket/netif/*.sec)

include socket/netif/tests/Makefile

