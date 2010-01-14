#!/bin/bash
#
# This script installs OLVER on the user system
#

echo
echo "OLVER Test Suite checks the operating system interfaces"
echo "for conformance to the LSB 3.2 Core (ISO/IEC 23360) standard."
echo

if [ `id -u` -ne 0 ]; then
	echo "Error: this script should be run with root priviledges."
	exit 1
fi

cd ${0%/*}

TESTER=`cat ./etc/olver.conf | grep USER_NAME_TESTER | sed 's/.*=\s*//'`
id $TESTER > /dev/null 2>&1
if [ $? -ne 0 ]; then
	echo "Error: there is no such a user '$TESTER'"
	exit 1
fi

# terminfo
mkdir -p /usr/share/terminfo/o
cp -f ./bin/terminfo/o/olverct /usr/share/terminfo/o/
chmod 755 /usr/share/terminfo/o/olverct

# testdata
./src/testdata/install_testdata.sh

# ini file for SAX parser
echo > ./tools/share/perl/SAX.ini
chown $TESTER:olver ./tools/share/perl/SAX.ini
chmod 664 ./tools/share/perl/SAX.ini

# agent.log
mkdir -p /tmp/olver-log
chown -R $TESTER:olver /tmp/olver-log
chmod 755 /tmp/olver-log

# Additional directories
chown $TESTER:olver /usr/share/terminfo/o/olverct
mkdir -p -m 755 /var/opt/lsb/test/olver-core
chown $TESTER:olver /var/opt/lsb/test/olver-core

exit 0
