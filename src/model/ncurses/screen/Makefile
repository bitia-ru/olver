SCREEN_SOURCES =



SOURCES += $(SCREEN_SOURCES:%.c=ncurses/screen/%.c)
SOURCES += $(wildcard ncurses/screen/*_config.c)
SEC_SOURCES += $(wildcard ncurses/screen/*.sec)

include ncurses/screen/tests/Makefile

