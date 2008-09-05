TIME_CONVERSION_SOURCES = convertionAlgorithms.c



SOURCES += $(TIME_CONVERSION_SOURCES:%.c=time/conversion/%.c)
SOURCES += $(wildcard time/conversion/*_config.c)
SEC_SOURCES += $(wildcard time/conversion/*.sec)

include time/conversion/tests/Makefile

