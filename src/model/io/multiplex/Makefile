MULTIPLEX_SOURCES =



SOURCES += $(MULTIPLEX_SOURCES:%.c=io/multiplex/%.c)
SOURCES += $(wildcard io/multiplex/*_config.c)
SEC_SOURCES += $(wildcard io/multiplex/*.sec)

include io/multiplex/tests/Makefile

