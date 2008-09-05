TLS_SOURCES =



SOURCES += $(TLS_SOURCES:%.c=pthread/tls/%.c)
SOURCES += $(wildcard pthread/tls/*_config.c)
SEC_SOURCES += $(wildcard pthread/tls/*.sec)

include pthread/tls/tests/Makefile

