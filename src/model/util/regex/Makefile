REGEX_SOURCES =



SOURCES += $(REGEX_SOURCES:%.c=util/regex/%.c)
SOURCES += $(wildcard util/regex/*_config.c)
SEC_SOURCES += $(wildcard util/regex/*.sec)

include util/regex/tests/Makefile

