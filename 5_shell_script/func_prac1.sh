#! /bin/bash

display() {
	echo "This is the msg from the function"
	echo "the parameter passed from calling process is" $1 $2 
}

display "A1, A2"
display "B1", "B2"
display "C1" "C2" "C3"
display "D1 D2 D3 D4"
display "E1", "E2," "E3", "E4," "E5"
