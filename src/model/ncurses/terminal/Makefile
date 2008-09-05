TERMINAL_SOURCES =



SOURCES += $(TERMINAL_SOURCES:%.c=ncurses/terminal/%.c)
SOURCES += $(wildcard ncurses/terminal/*_config.c)
SEC_SOURCES += $(wildcard ncurses/terminal/*.sec)

include ncurses/terminal/tests/Makefile

