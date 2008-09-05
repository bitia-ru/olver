SYSLOG_SOURCES =



SOURCES += $(SYSLOG_SOURCES:%.c=io/syslog/%.c)
SOURCES += $(wildcard io/syslog/*_config.c)
SEC_SOURCES += $(wildcard io/syslog/*.sec)

include io/syslog/tests/Makefile

