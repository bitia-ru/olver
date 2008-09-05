MUTEX_SOURCES =



SOURCES += $(MUTEX_SOURCES:%.c=pthread/mutex/%.c)
SOURCES += $(wildcard pthread/mutex/*_config.c)
SEC_SOURCES += $(wildcard pthread/mutex/*.sec)

include pthread/mutex/tests/Makefile

