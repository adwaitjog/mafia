#!/bin/bash

mylist=`cat apps.txt`
set -- $mylist

for benchmark; do
        cd singleapps_nostream/$benchmark\_NoStream
        qsub pbs_$benchmark\_NoStream.pbs
        cd -
done

mylist2=`cat apps2.txt`
set -- $mylist2

for benchmark; do
        cd singleapps_nostream/$benchmark\_NoStream
        qsub pbs_$benchmark\_NoStream.pbs
        cd -
done

mylist3=`cat apps3.txt`
set -- $mylist3

for benchmark; do
        cd singleapps_nostream/$benchmark\_NoStream
        qsub pbs_$benchmark\_NoStream.pbs
        cd -
done

mylist4=`cat apps4.txt`
set -- $mylist4

for benchmark; do
        cd singleapps_nostream/$benchmark\_NoStream
        qsub pbs_$benchmark\_NoStream.pbs
        cd -
done
