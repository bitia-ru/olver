#!/bin/bash
pushd ${0%/*} &> /dev/null
cp ./src/olverterm/dep/o/olverct /usr/share/terminfo/o
result=$?
chown root:root ./bin/agent
((result = $result + $?))
chmod +s ./bin/agent
((result = $result + $?))
popd &> /dev/null
exit $result
