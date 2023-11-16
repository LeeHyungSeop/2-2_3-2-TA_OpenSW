#! /bin/bash

test_for() {

	for x in $* ; do

		echo "$x"

	done
	
}

test_for hello world bye good morning
