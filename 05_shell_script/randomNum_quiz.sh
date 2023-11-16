#! /bin/bash

echo "Random number range(max : 32768) : 100"
echo "Number Range : 1 ~ 100"

randNum=$(($RANDOM%100 + 1))
inputNum=0
inputCnt=0

while [ 1 ]
do
	echo -n "Enter the number : "
	read inputNum

	inputCnt=$(($inputCnt + 1))
	
	if [ $randNum -eq $inputNum ]
	then
		echo "Congration! Answer is $randNum"
		echo "Count : $inputCnt"
		break
	elif [ $randNum -lt $inputNum ]
	then
		echo "answer is less than $inputNum"
	elif [ $randNum -gt $inputNum ]
	then
		echo "answer is greater than $inputNum"
	fi
done
