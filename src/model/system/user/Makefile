USER_SOURCES =



SOURCES += $(USER_SOURCES:%.c=system/user/%.c)
SOURCES += $(wildcard system/user/*_config.c)
SEC_SOURCES += $(wildcard system/user/*.sec)

include system/user/tests/Makefile

