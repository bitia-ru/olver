RPC_SOURCES =



SOURCES += $(RPC_SOURCES:%.c=socket/rpc/%.c)
SOURCES += $(wildcard socket/rpc/*_config.c)
SEC_SOURCES += $(wildcard socket/rpc/*.sec)

include socket/rpc/tests/Makefile

