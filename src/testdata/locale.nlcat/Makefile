###########################################################
# Default goal
###########################################################
default_goal: all

###########################################################
# Parameters of compilation
###########################################################

###########################################################
# Main goals
###########################################################
all: catfirst.cat catsecond.cat catthird.cat
	@echo Build completed

catfirst.cat: catfirst.msg
	gencat catfirst.cat catfirst.msg

catsecond.cat: catsecond.msg
	gencat catsecond.cat catsecond.msg

catthird.cat: catthird.msg
	gencat catthird.cat catthird.msg

clean:
	rm -rf *.cat

.PHONY: all clean
