PROCESS_SOURCES =



SOURCES += $(PROCESS_SOURCES:%.c=process/process/%.c)
SOURCES += $(wildcard process/process/*_config.c)
SEC_SOURCES += $(wildcard process/process/*.sec)

include process/process/tests/Makefile

