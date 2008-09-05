ENVIRON_SOURCES =



SOURCES += $(ENVIRON_SOURCES:%.c=process/environ/%.c)
SOURCES += $(wildcard process/environ/*_config.c)
SEC_SOURCES += $(wildcard process/environ/*.sec)

include process/environ/tests/Makefile

