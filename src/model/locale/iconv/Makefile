ICONV_SOURCES =



SOURCES += $(ICONV_SOURCES:%.c=locale/iconv/%.c)
SOURCES += $(wildcard locale/iconv/*_config.c)
SEC_SOURCES += $(wildcard locale/iconv/*.sec)

include locale/iconv/tests/Makefile

