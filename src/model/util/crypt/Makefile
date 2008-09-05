CRYPT_SOURCES =



SOURCES += $(CRYPT_SOURCES:%.c=util/crypt/%.c)
SOURCES += $(wildcard util/crypt/*_config.c)
SEC_SOURCES += $(wildcard util/crypt/*.sec)

include util/crypt/tests/Makefile

