COMMON_SOURCES = ts_socket.c verbose.c explicit_fsm.c progress_timer.c

SOURCES += $(COMMON_SOURCES:%.c=common/%.c)

SOURCES += $(wildcard common/*_config.c)
SEC_SOURCES += $(wildcard common/*.sec)

COMMON_OLVER_DC_SOURCES = olver_dc.c
OLVER_DC_SOURCES += $(COMMON_OLVER_DC_SOURCES:%.c=common/%.c)
