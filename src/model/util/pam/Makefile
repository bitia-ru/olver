PAM_SOURCES =



SOURCES += $(PAM_SOURCES:%.c=util/pam/%.c)
SOURCES += $(wildcard util/pam/*_config.c)
SEC_SOURCES += $(wildcard util/pam/*.sec)

include util/pam/tests/Makefile

