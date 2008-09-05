RWLOCK_SOURCES =



SOURCES += $(RWLOCK_SOURCES:%.c=pthread/rwlock/%.c)
SOURCES += $(wildcard pthread/rwlock/*_config.c)
SEC_SOURCES += $(wildcard pthread/rwlock/*.sec)

include pthread/rwlock/tests/Makefile

