SYMLINK_SOURCES =



SOURCES += $(SYMLINK_SOURCES:%.c=fs/symlink/%.c)
SOURCES += $(wildcard fs/symlink/*_config.c)
SEC_SOURCES += $(wildcard fs/symlink/*.sec)

include fs/symlink/tests/Makefile

