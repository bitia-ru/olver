SIGACTION_SOURCES =



SOURCES += $(SIGACTION_SOURCES:%.c=signal/sigaction/%.c)
SOURCES += $(wildcard signal/sigaction/*_config.c)
SEC_SOURCES += $(wildcard signal/sigaction/*.sec)

include signal/sigaction/tests/Makefile

