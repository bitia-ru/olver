#!/bin/bash
#
# This script prepare OLVER for building and running
#

if [ `id -u` -ne 0 ]; then
	echo "Error: this script should be run with root priviledges."
	exit 1
fi

PATH=/usr/sbin:$PATH

cd ${0%/*}

# There is a necessity to have particular group and user beforehand because
# the files unpacked have to be owned by the correct user
echo "Choose an account that will be used for performing tests"
echo -n "(olver_tester by default):"
read TESTER
if [ -z "$TESTER" ]; then
	TESTER=olver_tester
fi

echo "Preparing tester account..."
cat /etc/group | grep ^olver: > /dev/null 2>/dev/null
if [ $? -ne 0 ]; then
	groupadd olver > /dev/null 2>/dev/null
	if [ $? = 0 ]; then
		echo "Group 'olver' was successfully added"
	else
		echo "Error: failed to add group 'olver'"
		echo "Try to do it manually"
	fi
fi

id $TESTER > /dev/null 2>/dev/null
if [ $? -ne 0 ]; then
	useradd -g olver -d /home/$TESTER -m -s /bin/sh -p "" -c "OLVER tester login" $TESTER > /dev/null 2>/dev/null
	if [ $? = 0 ]; then
		echo "User '$TESTER' was successfully added"
	else
		echo "Error: failed to add user '$TESTER' to the group 'olver'"
		echo "Try to do it manually"
	fi
else
	if [ `id $TESTER -g -n` != "olver" ]; then
		usermod -g olver -d /home/$TESTER -m -s /bin/sh -p "" -c "OLVER tester login" $TESTER > /dev/null 2>/dev/null
		if [ `id $TESTER -g -n` != "olver" ]; then
			echo "Error: failed to change initial group of '$TESTER' to 'olver'"
			echo "Try to do it manually"
		else
			echo "Initial group of '$TESTER' was successfully changed to 'olver'"
		fi
	fi
fi
echo "Done"
echo

sed "s/^\s*global\.USER_NAME_TESTER\s.*$/global\.USER_NAME_TESTER = ${TESTER}/" -i ./etc/olver.conf >/dev/null 2>/dev/null


# OLVER hardware configuration
ARCH=`uname -m | tr '[:upper:]' '[:lower:]'`
case $ARCH in
    i?86)
        ARCH_NUM=1; ARCH=i486 ;;
    ia64)
        ARCH_NUM=2 ;;
    ppc|powerpc)
        ARCH_NUM=3; ARCH=ppc ;;
    ppc64|powerpc64)
        ARCH_NUM=4; ARCH=ppc64 ;;
    s390)
        ARCH_NUM=5 ;;
    s390x)
        ARCH_NUM=6 ;;
    x86_64|x86-64)
        ARCH_NUM=7; ARCH=x86_64 ;;
    *)
        ARCH_NUM=1; ARCH=i486 ;;
esac

echo "Choose an architecture that corresponds to system tested"
echo "1) i486"
echo "2) ia64"
echo "3) ppc"
echo "4) ppc64"
echo "5) s390"
echo "6) s390x"
echo "7) x86_64"
echo -n "($ARCH by default):"

read USER_ARCH_NUM
if [ -z "$USER_ARCH_NUM" ]; then
	USER_ARCH_NUM=$ARCH_NUM
fi

case $USER_ARCH_NUM in
    1)
        ARCH=i486 ;;
    2)
        ARCH=ia64 ;;
    3)
        ARCH=ppc ;;
    4)
        ARCH=ppc64 ;;
    5)
        ARCH=s390;;
    6)
        ARCH=s390x ;;
    7)
        ARCH=x86_64 ;;
    *)
        echo "Error: no such a value, use $ARCH instead"; USER_ARCH_NUM=$ARCH_NUM ;;
esac

sed "s/^\s*global\.TARGET_DATA_TYPES_ARCH\s.*$/global\.TARGET_DATA_TYPES_ARCH = ${USER_ARCH_NUM}/" -i ./etc/olver.conf >/dev/null 2>/dev/null
echo "OLVER was configured for $ARCH architecture"
echo "Done"
echo

echo "Setting up permissions..."
chown -R $TESTER:olver .
find . -type d -exec chmod 775 '{}' \; >/dev/null
find . -type f -exec chmod 664 '{}' \; >/dev/null
find ./bin -maxdepth 1 -type f ! -name 'testplan' -exec chmod 775 '{}' \; >/dev/null
find . -name 'tjreport' -exec chmod 775 '{}' \; >/dev/null
find . -name 'secc' -exec chmod 775 '{}' \; >/dev/null
find . -name 'stargen' -exec chmod 775 '{}' \; >/dev/null
find . -name '*.sh' -exec chmod 775 '{}' \; >/dev/null
find . -name '*.pl' -exec chmod 775 '{}' \; >/dev/null
find . -name '*.exe' -exec chmod 775 '{}' \; >/dev/null
find . -name '*.bat' -exec chmod 775 '{}' \; >/dev/null
echo "Done"

echo
echo "You should build and run tests as $TESTER"
echo
exit 0;
