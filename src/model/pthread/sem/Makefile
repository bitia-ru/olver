SEM_SOURCES =



SOURCES += $(SEM_SOURCES:%.c=pthread/sem/%.c)
SOURCES += $(wildcard pthread/sem/*_config.c)
SEC_SOURCES += $(wildcard pthread/sem/*.sec)

include pthread/sem/tests/Makefile

