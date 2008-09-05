MESSAGES_SOURCES =



SOURCES += $(MESSAGES_SOURCES:%.c=locale/messages/%.c)
SOURCES += $(wildcard locale/messages/*_config.c)
SEC_SOURCES += $(wildcard locale/messages/*.sec)

include locale/messages/tests/Makefile

