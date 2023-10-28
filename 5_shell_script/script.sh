#! /bin/bash

test_func() {

	echo "$0"
	echo "$1 $2"
	echo "$*"
	echo "$#"

}

#test_func hello world bye world hi

echo "$0"
echo "$*"
echo "$#"
