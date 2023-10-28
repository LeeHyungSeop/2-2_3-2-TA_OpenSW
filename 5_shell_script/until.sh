#! /bin/bash

echo "Enter a number : "
read NUM

pNum=1

until [ $pNum -gt $NUM ]
do 
	echo "$pNum"
	pNum=$(($pNum+2))
done
