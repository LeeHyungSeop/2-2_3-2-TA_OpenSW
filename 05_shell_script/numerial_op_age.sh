#! /bin/bash

echo "Enter your age : "
read AGE

if [ $AGE -ge 20 ] && [ $AGE -lt 30 ]
then
	echo "You are in 20s"
elif [ $AGE -ge 30 ] && [ $AGE -lt 40 ]
then
	echo "You are in 30s"
elif [ $AGE -ge 40 ] && [ $AGE -lt 50 ]
then
	echo "Your are in 40s"
else
	echo "You are out of range"
fi
