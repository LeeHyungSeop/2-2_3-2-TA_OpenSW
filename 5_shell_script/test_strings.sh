#! /bin/bash

echo "Enter any color code [R or G or B]"

read COLOR
echo $COLOR

if [ $COLOR == R ]
then
	echo "It's Red color"
elif [ "$COLOR" == "G" ]
then
	echo "It's Green color"
else
	echo "It's Blue color"
fi
