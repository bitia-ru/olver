SIGSTR_SOURCES =



SOURCES += $(SIGSTR_SOURCES:%.c=signal/sigstr/%.c)
SOURCES += $(wildcard signal/sigstr/*_config.c)
SEC_SOURCES += $(wildcard signal/sigstr/*.sec)

include signal/sigstr/tests/Makefile

