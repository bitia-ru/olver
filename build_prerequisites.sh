#!/bin/bash
#
# Check Prerequisites to Build OLVER
#

check_gcc=0
check_gpp=0
check_ncurses=0

check_lsbcc=0
check_lsb_so=0
check_jre=0
check_autoconf=0
check_automake=0
check_libtool=0

issue_count=1

#
# Perform Checks
#

echo "Checking build prerequisites..."

# Check for gcc
gcc -v &> /dev/null
if [ $? -eq 0 ]; then
	check_gcc=1
	CC=gcc
fi

# Check for g++
g++ -v &> /dev/null
if [ $? -eq 0 ]; then
	check_gpp=1
fi

# Check for lsbcc
which /opt/lsb/bin/lsbcc &> /dev/null
if [ $? -eq 0 ]; then
	check_lsbcc=1
	CC=/opt/lsb/bin/lsbcc
	# LSB Runtime
	ls -l /lib64/ld-lsb*.3 &> /dev/null
	if [ $? -eq 0  ]; then
		check_lsb_so=1
	else
		ls -l /lib/ld-lsb*.3 &> /dev/null
		if [ $? -eq 0  ]; then
			check_lsb_so=1
		fi
	fi
fi

# Check for ncurses
cat > hello-ncurses.c << EOF
#include <ncurses.h>

int main()
{	
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}
EOF
NCURSES_STR=`$CC -lncurses hello-ncurses.c -o hello-ncurses -v 2>&1 | grep "cannot find -lncurses"`
if test "_$NCURSES_STR" = "_" ;then
	check_ncurses=1
	rm -f hello-ncurses*
fi

# Java Runtime Environment
JAVA_VERSION=`java -version 2>&1 | grep 'java version \"1\.[56789]'`
JAVA_VERSION_2=`java -version 2>&1 | grep 'java version \"[23456789]\.[0123456789]'`

if [[ "_$JAVA_VERSION" != "_"  || "_$JAVA_VERSION_2" != "_" ]]
then
	check_jre=1
fi

# Check for autoconf
autoconf --version &> /dev/null
if [ $? -eq 0 ]; then
	check_autoconf=1
fi

# Check for automake
automake --version &> /dev/null
if [ $? -eq 0 ]; then
	check_automake=1
fi

# Check for libtool
libtool --version &> /dev/null
if [ $? -eq 0 ]; then
	check_libtool=1
fi

#
# Report Errors
#
if [[ $check_lsbcc = 0 || $check_lsb_so = 0 || $check_jre = 0 || $check_autoconf = 0 || $check_automake = 0 || $check_libtool = 0 || $check_gcc = 0 || $check_gpp = 0 || $check_ncurses = 0 ]]; then
	echo
	echo "Several checks failed. Please, see details below."
	echo
fi

if [ $check_gcc = 0 ] ; then
	echo "$issue_count) The gcc compiler and its development libraries should be installed."
	echo
	((issue_count++))
fi

if [ $check_gpp = 0 ] ; then
	echo "$issue_count) The g++ compiler should be installed."
	echo
	((issue_count++))
fi

if [ $check_ncurses = 0 ] ; then
	echo "$issue_count) The ncurses development library should be installed."
	echo
	((issue_count++))
fi

if [ $check_lsbcc = 0 ]; then
	echo "$issue_count) LSB 4.1 Software Development Kit (SDK) should be installed."
	echo "   You may download it at http://www.linuxfoundation.org/collaborate/workgroups/lsb/download."
	echo
	((issue_count++))
else
	if [ $check_lsb_so = 0 ]; then
		echo "$issue_count) LSB runtime loader is required."
		echo
		((issue_count++))
	fi
fi

if [ $check_jre = 0 ] ; then
	echo "$issue_count) Please, make sure you have JRE 1.5 or later installed"
	echo "   and 'java' command is on your path. JRE is needed to build SEC files."
	echo
	((issue_count++))
fi

if [ $check_autoconf = 0 ] ; then
	echo "$issue_count) Autoconf tool should be installed to build olverterm."
	echo
	((issue_count++))
fi

if [ $check_automake = 0 ] ; then
	echo "$issue_count) Automake tool should be installed to build olverterm."
	echo
	((issue_count++))
fi

if [ $check_libtool = 0 ] ; then
	echo "$issue_count) Libtool should be installed to build olverterm."
	echo
	((issue_count++))
fi


if [ $issue_count -gt 1 ]; then
	echo "Fatal errors. Can not continue."
        exit 1
fi

echo "Ok"
exit 0
