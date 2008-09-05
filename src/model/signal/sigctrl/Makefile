SIGCTRL_SOURCES =



SOURCES += $(SIGCTRL_SOURCES:%.c=signal/sigctrl/%.c)
SOURCES += $(wildcard signal/sigctrl/*_config.c)
SEC_SOURCES += $(wildcard signal/sigctrl/*.sec)

include signal/sigctrl/tests/Makefile

