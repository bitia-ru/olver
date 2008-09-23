#!/bin/bash
#
# This script builds the tests
#

#
# Parse options
#
while getopts ":p" Option
do
    case $Option in
    'p'   ) PACKAGE_MODE=1
            ;;
    *     ) echo "-$OPTARG: unknown option"
            echo
            echo "Usage: build_conf_tests.sh [-p]"
            echo "Options:"
            echo "  -p: package build mode, don't set permissions for agent"
            exit 1
            ;;
    esac
done
shift $(($OPTIND - 1))

#
# Adjust Directory
#
pushd ${0%/*} > /dev/null 2>&1

# Checking prerequisites
./build_prerequisites.sh

if [ ! $? = 0 ]; then
    exit 2;
fi
	
# Set environment
DIR=$(cd "." && pwd)
CTESK_HOME=$DIR/tools/CTesK
export CTESK_HOME
PATH=$PATH:$CTESK_HOME/bin:/opt/lsb/bin
export PATH

mkdir -p bin/terminfo/o > /dev/null 2>&1
cp ./src/olverterm/dep/olverct.terminfo ./bin/terminfo > /dev/null 2>&1
cp ./src/olverterm/dep/o/olverct ./bin/terminfo/o > /dev/null 2>&1

# Build status
handbook_build_status=1
config_generation_status=1
testdata_build_status=1
olverterm_build_status=1
agent_build_status=1
launch_build_status=1
ctesk_lib_build_status=1
model_build_status=1
agent_permission_status=1
	
#
# Step 1: Build handbook
#
echo "Building handbook ..."
cd config
make all
handbook_build_status=$?
cd ..

#
# Step 2: Generate configuration files
#
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DIR/config/bin
echo "Generating configuration files ..."
cd src/model
../../config/bin/handbook -o ../../config/olver.tree -d ../../config/default.conf -g -h .
config_generation_status=$?
cd ../..

#
# Step 3: Build test data
#
echo "Building test data ..."
cd src/testdata
./build_testdata.sh
testdata_build_status=$?
cd ../..

#
# Step 4: Build agent
#
echo "Building agent ..."
cd src/agent
./build_config.sh
make all
agent_build_status=$?
cd ../..


#
# Step 5: Build launcher
#
echo "Building CTesk launcher ..."
cd ./tools/CTesK/native-java-launcher
make
launch_build_status=$?
cp -f ./launcher ../bin/secc
cp -f ./launcher ../../TraceTools/bin/stargen
cp -f ./launcher ../../TraceTools/bin/trig
cd ../../..


#
# Step 6: Build CTesK libraries
#
echo "Building CTesk libraries ..."
cd ./tools/CTesK/lib/src
make
ctesk_lib_build_status=$?
cp -f ./libctesk.a ../../lib/gcc/
cd ../../../..


#
# Step 7: Build model
#
echo "Building model ..."
cd src/model
make all
model_build_status=$?
cd ../..

#
# Step 8: Copy binaries and set agent permissions
#
if [ -z $PACKAGE_MODE ]; then
    if [ `id -u` -ne 0 ]; then 
    	echo "Need root privileges"
    	OLVER_SU_CMD="su root -- -c"
    	which sudo 2>&1 > /dev/null
    	if [ $? -eq 0 ]; then
    		echo -n "You have sudo available.  Should I use it? "
    		read answer
    		answer=`echo ${answer} | cut -c1`
    		if [ "${answer}" = "y" -o "${answer}" = "Y" ]; then
    		    OLVER_SU_CMD="sudo /bin/sh -c"
    		fi
    		echo
    	fi
        
    	echo "Using the command "${OLVER_SU_CMD}" to gain root access.  Please type the"
    	echo "appropriate password if prompted."
    	echo " "
    else
        echo "Already have root privileges"
        OLVER_SU_CMD="/bin/sh -c"
    fi
    
    echo "Setting permissions for the test agent..."
    $OLVER_SU_CMD ./agent_perm.sh
    agent_permission_status=$?
    if [ $agent_permission_status = 0 ]; then
    	echo "Agent attributes changed"
    else
        echo "Failed. Try to do it manually using agent_perm.sh"
    fi
else
    agent_permission_status=0
fi

if [ -e bin/olverterm ]; then
	olverterm_build_status=0
fi

#
# Step 9: Report build status
#
echo ""
if [ $handbook_build_status = 0 ]; then
	echo "Build status for handbook .............. PASSED"
else
	echo "Build status for handbook .............. FAILED"
fi	
if [ $config_generation_status = 0 ]; then
	echo "Build status for configuration files ... PASSED"
else
	echo "Build status for configuration files ... FAILED"
fi	
if [ $testdata_build_status = 0 ]; then
	echo "Build status for test data ............. PASSED"
else
	echo "Build status for test data ............. FAILED"
fi	
if [ $olverterm_build_status = 0 ]; then
	echo "Build status for olverterm ............. PASSED"
else
	echo "Build status for olverterm ............. FAILED"
fi	
if [ $agent_build_status = 0 ]; then
	echo "Build status for agent ................. PASSED"
else
	echo "Build status for agent ................. FAILED"
fi	
if [ $launch_build_status = 0 ]; then
	echo "Build status for CTesk launcher ........ PASSED"
else
	echo "Build status for CTesk launcher ........ FAILED"
fi
if [ $ctesk_lib_build_status = 0 ]; then
	echo "Build status for CTesk library ......... PASSED"
else
	echo "Build status for CTesk library ......... FAILED"
fi
if [ $model_build_status = 0 ]; then
	echo "Build status for model ................. PASSED"
else
	echo "Build status for model ................. FAILED"
fi
if [ -z $PACKAGE_MODE ]; then
    if [ $agent_permission_status = 0 ]; then
    	echo "Setting agent permissions .............. PASSED"
    else
    	echo "Setting agent permissions .............. FAILED"
    fi
fi

if [[ $handbook_build_status = 0 && $config_generation_status = 0 && $testdata_build_status = 0 && $olverterm_build_status = 0 && $agent_build_status = 0 && $launch_build_status = 0 && $ctesk_lib_build_status = 0 && $model_build_status = 0 && $agent_permission_status = 0 ]]; then
	echo ""
	echo "Build status for OLVER ................. PASSED"
	exit 0
else
	echo ""	
	echo "Build status for OLVER ................. FAILED"
	exit 1
fi

#
# Restore Directory
#
popd > /dev/null 2>&1
