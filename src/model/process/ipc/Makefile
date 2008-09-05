IPC_SOURCES =



SOURCES += $(IPC_SOURCES:%.c=process/ipc/%.c)
SOURCES += $(wildcard process/ipc/*_config.c)
SEC_SOURCES += $(wildcard process/ipc/*.sec)

include process/ipc/tests/Makefile

