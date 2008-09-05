PTHREAD_SOURCES =



SOURCES += $(PTHREAD_SOURCES:%.c=pthread/pthread/%.c)
SOURCES += $(wildcard pthread/pthread/*_config.c)
SEC_SOURCES += $(wildcard pthread/pthread/*.sec)

include pthread/pthread/tests/Makefile

