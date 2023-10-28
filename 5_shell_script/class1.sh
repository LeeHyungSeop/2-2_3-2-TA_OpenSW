#! /bin/bash 

test_func() {

	file_list=$(ls *.txt)
	for file in $file_list; do
		wc_cnt=$(cat $file | wc -w)
		echo "$file $wc_cnt"
	done

}

test_func
