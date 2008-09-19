###########################################################
# Default goal
###########################################################
default_goal: all

###########################################################
# Parameters of compilation
###########################################################

PDOMAINS=Path1/en_US/LC_MESSAGES/testdomain.po Path2/en_US/LC_MESSAGES/anotherdomain.po
DOMAINS=$(PDOMAINS:%.po=%.mo)

###########################################################
# Main goals
###########################################################
all: $(DOMAINS)
	@echo Build completed

$(DOMAINS): $(PDOMAINS)
	msgfmt $(@:%.mo=%.po) -o $@

clean:
	@rm -rvf $(DOMAINS)

.PHONY: all clean
