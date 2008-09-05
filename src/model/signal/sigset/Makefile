SIGSET_SOURCES =



SOURCES += $(SIGSET_SOURCES:%.c=signal/sigset/%.c)
SOURCES += $(wildcard signal/sigset/*_config.c)
SEC_SOURCES += $(wildcard signal/sigset/*.sec)

include signal/sigset/tests/Makefile

