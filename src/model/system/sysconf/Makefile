SYSCONF_SOURCES =



SOURCES += $(SYSCONF_SOURCES:%.c=system/sysconf/%.c)
SOURCES += $(wildcard system/sysconf/*_config.c)
SEC_SOURCES += $(wildcard system/sysconf/*.sec)

include system/sysconf/tests/Makefile

