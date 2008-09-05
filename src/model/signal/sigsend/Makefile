SIGSEND_SOURCES =



SOURCES += $(SIGSEND_SOURCES:%.c=signal/sigsend/%.c)
SOURCES += $(wildcard signal/sigsend/*_config.c)
SEC_SOURCES += $(wildcard signal/sigsend/*.sec)

include signal/sigsend/tests/Makefile

