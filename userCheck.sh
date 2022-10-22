#!/bin/bash

check=$(cat accountStorage.txt | grep "[|]a[-]")
match=${#check}
if [ $match -gt 0 ]; then
    echo "1"
else
    echo "0"
fi

exit $?