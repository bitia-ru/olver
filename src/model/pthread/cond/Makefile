COND_SOURCES =



SOURCES += $(COND_SOURCES:%.c=pthread/cond/%.c)
SOURCES += $(wildcard pthread/cond/*_config.c)
SEC_SOURCES += $(wildcard pthread/cond/*.sec)

include pthread/cond/tests/Makefile

