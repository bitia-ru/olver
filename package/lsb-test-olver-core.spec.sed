# name, ver, rel are passed in from Makefile so we only have to set them one place
%define name @NAME@
%define ver @VERSION@
%define rel @RELEASE@

Summary: LSB OLVER Core Test Suite
Vendor: ISPRAS

Name: %{name}
Version: %{ver}
Release: %{rel}
Source: %{name}-%{ver}-%{rel}.src.tgz
License: GPL
URL: http://www.linux-foundation.org/en/Downloads
Group: Development/Tools
Buildroot: %{_builddir}/%{name}-root
AutoReqProv: no

%description
OLVER Test Suite checks the operating system interfaces for conformance to the LSB 3.1 Core (ISO/IEC 23360) standard.

%prep
if [ ! -x /opt/lsb/bin/lsbcc ] ; then
    echo "lsbcc not found, required for compilation, aborting"
    exit 1
fi

%setup -q

%build
./build_conf_tests.sh -p

%install

SOURCE=`cd . && pwd`
if [ ! -z "${RPM_BUILD_ROOT}"  -a "${RPM_BUILD_ROOT}" != "/" ]; then
    rm -rf ${RPM_BUILD_ROOT}/*
fi
mkdir -p ${RPM_BUILD_ROOT}/opt/lsb/test/olver-core
cd ${RPM_BUILD_ROOT}/opt/lsb/test/olver-core

# Binary section
mkdir bin
mkdir bin/terminfo
mkdir -p ../../../../usr/share/terminfo/o

cp -f $SOURCE/bin/olver bin/olver
cp -f $SOURCE/bin/agent bin/agent
cp -f $SOURCE/bin/olverterm bin/olverterm
cp -f $SOURCE/bin/terminfo/olverct.terminfo bin/terminfo/olverct.terminfo
cp -f $SOURCE/bin/terminfo/o/olverct ../../../../usr/share/terminfo/o/olverct

cp -f $SOURCE/bin/olver_run_tests bin/olver_run_tests
cp -f $SOURCE/bin/olver_pre bin/olver_pre
cp -f $SOURCE/bin/olver_report bin/olver_report
cp -f $SOURCE/bin/testplan bin/testplan

# Configuration section
mkdir etc
cp -f $SOURCE/etc/olver.conf etc/
cp -f $SOURCE/etc/times.ref etc/

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
        echo "Error: Couldn't determine architecture from 'uname' output '$ARCH'"; ARCH_NUM=1; ARCH=i486 ;;
esac
echo "OLVER was configured for $ARCH architecture"

sed "s/^\s*global\.TARGET_DATA_TYPES_ARCH\s.*$/global\.TARGET_DATA_TYPES_ARCH = ${ARCH_NUM}/" -i ./etc/olver.conf >/dev/null 2>/dev/null
sed 's/^\s*global\.TEST_DATA_PATH\s.*$/global\.TEST_DATA_PATH = \/opt\/lsb\/test\/olver-core\/testdata/' -i ./etc/olver.conf >/dev/null 2>/dev/null
sed 's/^\s*global\.USER_NAME_TESTER\s.*$/global\.USER_NAME_TESTER = olver_tester/' -i ./etc/olver.conf >/dev/null 2>/dev/null

# Tools section
mkdir tools
mkdir tools/BugDB
mkdir tools/TraceTools
mkdir tools/reportgen
mkdir -p tools/share/perl/XML
cp -f $SOURCE/tools/BugDB/BugDB.xml tools/BugDB/BugDB.xml
cp -f $SOURCE/tools/BugDB/Readme.doc tools/BugDB/Readme.doc
cp -rf $SOURCE/tools/TraceTools/* tools/TraceTools/
cp -rf $SOURCE/tools/reportgen/* tools/reportgen/
cp -rf $SOURCE/tools/share/perl/XML/* tools/share/perl/XML/

# Testdata section
mkdir -p testdata

cp -f $SOURCE/src/testdata/install_testdata.sh testdata/
cp -f $SOURCE/src/testdata/uninstall_testdata.sh testdata/
cp -rf $SOURCE/src/testdata/math.exp testdata/
cp -rf $SOURCE/src/testdata/math.trig testdata/
cp -rf $SOURCE/src/testdata/math.bessel testdata/
cp -rf $SOURCE/src/testdata/locale.locale testdata/

mkdir -p testdata/util.dl
cp -f $SOURCE/src/testdata/util.dl/libmy.so testdata/util.dl

mkdir -p testdata/locale.textdomain/Path1/Olver_Locale/LC_MESSAGES
cp -f $SOURCE/src/testdata/locale.textdomain/Path1/Olver_Locale/LC_MESSAGES/testdomain.po testdata/locale.textdomain/Path1/Olver_Locale/LC_MESSAGES

mkdir -p testdata/locale.textdomain/Path2/Olver_Locale/LC_MESSAGES
cp -f $SOURCE/src/testdata/locale.textdomain/Path2/Olver_Locale/LC_MESSAGES/anotherdomain.po testdata/locale.textdomain/Path2/Olver_Locale/LC_MESSAGES

mkdir testdata/locale.nlcat
find $SOURCE/src/testdata/locale.nlcat -name '*.msg' -exec cp -f '{}' testdata/locale.nlcat/ \; >/dev/null 2>/dev/null

# Document section
mkdir doc
cp -rf $SOURCE/doc/* doc/

#${RPM_BUILD_ROOT}
cd ../../../..

find opt/lsb/test/olver-core -type d -exec chmod 775 '{}' \; >/dev/null
find opt/lsb/test/olver-core -type f -exec chmod 664 '{}' \; >/dev/null
find opt/lsb/test/olver-core/bin -maxdepth 1 -type f ! -name 'testplan' -exec chmod 775 '{}' \; >/dev/null
find opt/lsb/test/olver-core -name 'tjreport' -exec chmod 775 '{}' \; >/dev/null
find opt/lsb/test/olver-core -name 'secc' -exec chmod 775 '{}' \; >/dev/null
find opt/lsb/test/olver-core -name 'stargen' -exec chmod 775 '{}' \; >/dev/null
find opt/lsb/test/olver-core -name '*.sh' -exec chmod 775 '{}' \; >/dev/null
find opt/lsb/test/olver-core -name '*.pl' -exec chmod 775 '{}' \; >/dev/null
find opt/lsb/test/olver-core -name '*.exe' -exec chmod 775 '{}' \; >/dev/null
find opt/lsb/test/olver-core -name '*.bat' -exec chmod 775 '{}' \; >/dev/null
chmod 775 usr/share/terminfo/o/olverct >/dev/null
chmod +s opt/lsb/test/olver-core/bin/agent >/dev/null

cd ..

%files
%defattr(-,olver_tester,olver)
%attr(-,root,root) /opt/lsb/test/olver-core/bin/agent
/opt/lsb/test/olver-core
%attr(-,root,root) %dir /usr/share/terminfo/o
/usr/share/terminfo/o/olverct

%pre
if [ "$1" = "1" -o "$1" = "install" ] ; then # install
PATH=/usr/sbin:$PATH

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

TESTER=olver_tester
id $TESTER > /dev/null 2>/dev/null
if [ $? -ne 0 ]; then
	useradd -g olver -d /home/$TESTER -s /bin/sh -c "OLVER tester login" $TESTER -m > /dev/null 2>/dev/null
	if [ $? = 0 ]; then
		echo "User '$TESTER' was successfully added"
	else
		echo "Error: failed to add user '$TESTER' to the group 'olver'"
		echo "Try to do it manually"
	fi
else
	if [ `id $TESTER -g -n` != "olver" ]; then
		usermod -g olver -d /home/$TESTER -m -s /bin/sh -c "OLVER tester login" $TESTER > /dev/null 2>/dev/null
		if [ `id $TESTER -g -n` != "olver" ]; then
			echo "Error: failed to change initial group of '$TESTER' to 'olver'"
			echo "Try to do it manually"
		else
			echo "Initial group of '$TESTER' was successfully changed to 'olver'"
		fi
	fi
fi
fi

%post
if [ "$1" = "1" -o \( "$1" = "configure" -a -z "$2" \) ] ; then  # install
/opt/lsb/test/olver-core/testdata/install_testdata.sh
echo > /opt/lsb/test/olver-core/tools/share/perl/SAX.ini
chown olver_tester:olver /opt/lsb/test/olver-core/tools/share/perl/SAX.ini
chmod 664 /opt/lsb/test/olver-core/tools/share/perl/SAX.ini
fi

%preun
if [ "$1" = "0" -o "$1" = "remove" ] ; then # remove
/opt/lsb/test/olver-core/testdata/uninstall_testdata.sh
rm -f /opt/lsb/test/olver-core/tools/share/perl/SAX.ini
fi

%postun
if [ "$1" = "0" -o "$1" = "remove" ] ; then # remove
PATH=/usr/sbin:$PATH

echo "Deleting tester account..."
TESTER=olver_tester
id $TESTER > /dev/null 2>/dev/null
if [ $? -eq 0 ]; then
	userdel -r $TESTER > /dev/null 2>/dev/null
	if [ $? = 0 ]; then
		echo "User '$TESTER' was successfully deleted"
	else
		echo "Warning: failed to delete user '$TESTER'"
	fi
fi

cat /etc/group | grep ^olver: > /dev/null 2>/dev/null
if [ $? -eq 0 ]; then
	groupdel olver > /dev/null 2>/dev/null
	if [ $? = 0 ]; then
		echo "Group 'olver' was successfully deleted."
	else
		echo "Warning: failed to delete group 'olver'."
	fi
fi
echo "Done"
fi

%clean
if [ ! -z "${RPM_BUILD_ROOT}"  -a "${RPM_BUILD_ROOT}" != "/" ]; then
    rm -rf ${RPM_BUILD_ROOT}
fi