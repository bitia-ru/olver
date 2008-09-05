WORDEXP_SOURCES =



SOURCES += $(WORDEXP_SOURCES:%.c=util/wordexp/%.c)
SOURCES += $(wildcard util/wordexp/*_config.c)
SEC_SOURCES += $(wildcard util/wordexp/*.sec)

include util/wordexp/tests/Makefile

