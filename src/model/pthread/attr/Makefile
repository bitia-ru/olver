ATTR_SOURCES =



SOURCES += $(ATTR_SOURCES:%.c=pthread/attr/%.c)
SOURCES += $(wildcard pthread/attr/*_config.c)
SEC_SOURCES += $(wildcard pthread/attr/*.sec)

include pthread/attr/tests/Makefile

