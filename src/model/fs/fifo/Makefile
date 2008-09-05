FIFO_SOURCES =



SOURCES += $(FIFO_SOURCES:%.c=fs/fifo/%.c)
SOURCES += $(wildcard fs/fifo/*_config.c)
SEC_SOURCES += $(wildcard fs/fifo/*.sec)

include fs/fifo/tests/Makefile

