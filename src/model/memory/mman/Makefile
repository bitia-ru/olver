MMAN_SOURCES =



SOURCES += $(MMAN_SOURCES:%.c=memory/mman/%.c)
SOURCES += $(wildcard memory/mman/*_config.c)
SEC_SOURCES += $(wildcard memory/mman/*.sec)

include memory/mman/tests/Makefile

