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
echo $OLVER_SU_CMD >olver_su_cmd.txt