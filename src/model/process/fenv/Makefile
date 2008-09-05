FENV_SOURCES =



SOURCES += $(FENV_SOURCES:%.c=process/fenv/%.c)
SOURCES += $(wildcard process/fenv/*_config.c)
SEC_SOURCES += $(wildcard process/fenv/*.sec)

include process/fenv/tests/Makefile

