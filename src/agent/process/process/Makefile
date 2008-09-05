PROCESS_SOURCES = process_agent.c process_common.c functionTypedValuesCall.c

PROCESS_ASM_SOURCES=$(wildcard process/process/functionCall_$(HOSTTYPE).s)
ifeq ($(strip $(PROCESS_ASM_SOURCES)),)
    PROCESS_SOURCES += functionCall.c
endif

SOURCES += $(PROCESS_SOURCES:%.c=process/process/%.c)
SOURCES += $(PROCESS_ASM_SOURCES)

