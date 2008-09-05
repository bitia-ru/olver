COMMON_SOURCES = main.c command.c system.c ta_cstrings.c

SOURCES += $(COMMON_SOURCES:%.c=common/%.c)


###########################################################
# Common agent library
###########################################################
COMMON_AGENT_LIBRARY_SOURCES = agent.c ta_assertion.c ta_hash.c ta_stream.c verbose.c

OLVER_DAEMON_SOURCES=common/olver_daemon.c

AGENT_LIBRARIES += common/libagent.a

common/libagent.a: $(COMMON_AGENT_LIBRARY_SOURCES:%.c=common/%.o)
	$(MAKEAR) $@ $(COMMON_AGENT_LIBRARY_SOURCES:%.c=common/%.o)
	ranlib $@

olver_daemon: $(COMMON_AGENT_LIBRARY_SOURCES:%.c=common/%.o)

CLEAN_MODULES += clean_libagent	

clean_libagent:
	rm -f $(COMMON_AGENT_LIBRARY_SOURCES:%.c=common/%.o)
	rm -f common/libagent.a
