#
# Check Prerequisites to Build OLVER
#

check_gcc=0
check_gpp=0
check_ncurses=0

check_antlr=0
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
fi

# Check for g++
g++ -v &> /dev/null
if [ $? -eq 0 ]; then
	check_gpp=1
fi

# Check for ncurses
NCURSES_STR=`gcc -lncurses -v 2>&1 | grep "cannot find -lncurses"`
if test "_$NCURSES_STR" = "_" ;then
	check_ncurses=1
fi

# Check antlr if needed
if [ -f "./src/model/pthread/attr/attr_config.c" ]
then
	check_antlr=1
else
	ANTLR_STR=`antlr 2>&1 | grep "Version 1.33"`
	if ! test "_$ANTLR_STR" = "_" ; then
		check_antlr=1
	fi
fi

# Check for lsbcc
which /opt/lsb/bin/lsbcc &> /dev/null
if [ $? -eq 0 ]; then
	check_lsbcc=1
	# LSB Runtime
	ls -l /lib/ld-lsb*.3 &> /dev/null
	if [ $? -eq 0  ]; then
		check_lsb_so=1
	else
		echo "Creating symbolic link for the LSB Runtime loader..."
		CUR_ARCH=`uname -m`
		
		./ask_root.sh
		SU_CMD=`cat olver_su_cmd.txt`
		rm -f ./olver_su_cmd.txt
		if [ -f /lib/ld-linux.so.2 ]; then
			$SU_CMD "ln -s /lib/ld-linux.so.2 /lib/ld-lsb.so.3"
		fi
		if [ -f /lib/ld-linux-$CUR_ARCH.so.2 ]; then
			$SU_CMD "ln -s /lib/ld-linux-$CUR_ARCH.so.2 /lib/ld-lsb-$CUR_ARCH.so.3"
		fi
		check_lsb_so=1
	fi
fi

# Java Runtime Environment
JAVA_SUN=`java -version 2>&1 | grep "HotSpot(TM)"`
JAVA_IBM=`java -version 2>&1 | grep "IBM"`
JAVA_OpenJDK=`java -version 2>&1 | grep "OpenJDK"`
JAVA_VERSION=`java -version 2>&1 | grep 'java version \"1\.[56789]'`
JAVA_VERSION_2=`java -version 2>&1 | grep 'java version \"[23456789]\.[0123456789]'`

if [[ "_$JAVA_SUN" != "_" || "_$JAVA_IBM" != "_" || "_$JAVA_OpenJDK" != "_" ]]; then
	if [[ "_$JAVA_VERSION" != "_"  || "_$JAVA_VERSION_2" != "_" ]]
	then
		check_jre=1
	fi
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
if [[ $check_antlr = 0 || $check_lsbcc = 0 || $check_lsb_so = 0 || $check_jre = 0 || $check_autoconf = 0 || $check_automake = 0 || $check_libtool = 0 || $check_gcc = 0 || $check_gpp = 0 || $check_ncurses = 0 ]]; then
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

if [ $check_antlr = 0 ]; then
	echo "$issue_count) Antlr version 1.33 is required to be installed"
	echo "   to build grammar files."
	echo
	((issue_count++))
fi

if [ $check_lsbcc = 0 ]; then
	echo "$issue_count) LSB 3.1 Software Development Kit (SDK) should be installed."
	echo "   You may download it at  http://www.linux-foundation.org/en/Downloads."
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
	echo "$issue_count) Please, make sure you have OpenJDK, Sun or IBM JRE 5 or later installed"
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
