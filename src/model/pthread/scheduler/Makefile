SCHEDULER_SOURCES =



SOURCES += $(SCHEDULER_SOURCES:%.c=pthread/scheduler/%.c)
SOURCES += $(wildcard pthread/scheduler/*_config.c)
SEC_SOURCES += $(wildcard pthread/scheduler/*.sec)

include pthread/scheduler/tests/Makefile

