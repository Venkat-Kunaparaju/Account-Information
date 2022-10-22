#!/bin/bash


scoreLength=0
check=$1
match=${#check}
if [ $match -gt 8 ]; then
    scoreLength=1
fi

scoreSpecial=0
check=$(echo $1 | grep "[!@$%^&*()]")
match=${#check}
if [ $match -gt 0 ]; then
    scoreSpecial=1
fi

scoreNumber=0
check=$(echo $1 | grep "[0-9]")
match=${#check}
if [ $match -gt 0 ]; then
    scoreNumber=1
fi

scoreUpper=0
check=$(echo $1 | grep "[A-Z]")
match=${#check}
if [ $match -gt 0 ]; then
    scoreUpper=1
fi

scoreLower=0
check=$(echo $1 | grep "[a-z]")
match=${#check}
if [ $match -gt 0 ]; then
    scoreLower=1
fi

echo $scoreLength$scoreSpecial$scoreNumber$scoreUpper$scoreLower

exit $?