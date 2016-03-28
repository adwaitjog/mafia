#!/bin/bash

mylist=`cat apps.txt`
set -- $mylist

for benchmark; do
	    cat script_base_singleapp.pbs | sed -e "s/JPEG/$benchmark/g" > singleapps/$benchmark/pbs_$benchmark.pbs
done

mylist2=`cat apps2.txt`
set -- $mylist2

for benchmark; do
	    cat script_base_singleapp.pbs | sed -e "s/JPEG/$benchmark/g" > singleapps/$benchmark/pbs_$benchmark.pbs
done
mylist3=`cat apps3.txt`
set -- $mylist3

for benchmark; do
	    cat script_base_singleapp.pbs | sed -e "s/JPEG/$benchmark/g" > singleapps/$benchmark/pbs_$benchmark.pbs
done

mylist4=`cat apps4.txt`
set -- $mylist4

for benchmark; do
	    cat script_base_singleapp.pbs | sed -e "s/JPEG/$benchmark/g" > singleapps/$benchmark/pbs_$benchmark.pbs
done