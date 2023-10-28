#! /bin/bash

test_txt_wordcount(){
        txt_files=$(ls)
        for file in $txt_files; do
                if [ ! -x $file ]; then
                        word_count=$(cat $file | wc -w)
                        echo $file $word_count
                fi
        done
}

test_txt_wordcount
