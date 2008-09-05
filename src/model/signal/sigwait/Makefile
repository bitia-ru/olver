SIGWAIT_SOURCES =



SOURCES += $(SIGWAIT_SOURCES:%.c=signal/sigwait/%.c)
SOURCES += $(wildcard signal/sigwait/*_config.c)
SEC_SOURCES += $(wildcard signal/sigwait/*.sec)

include signal/sigwait/tests/Makefile

