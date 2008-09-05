WCTYPE_SOURCES =



SOURCES += $(WCTYPE_SOURCES:%.c=locale/wctype/%.c)
SOURCES += $(wildcard locale/wctype/*_config.c)
SEC_SOURCES += $(wildcard locale/wctype/*.sec)

include locale/wctype/tests/Makefile

