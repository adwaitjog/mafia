#!/bin/bash

mylist=`cat apps.txt`
set -- $mylist

for APP1; do
        shift
        for APP2; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
done
mylist2=`cat apps2.txt`
set -- $mylist2

for APP1; do
        shift
        for APP2; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
done

mylist3=`cat apps3.txt`
set -- $mylist3

for APP1; do
        shift
        for APP2; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
done

mylist4=`cat apps4.txt`
set -- $mylist4

for APP1; do
        shift
        for APP2; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
done

for APP1 in $mylist; do
        for APP2 in $mylist2; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
		shift
done

for APP1 in $mylist; do
        for APP2 in $mylist3; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
		shift
done

for APP1 in $mylist; do
        for APP2 in $mylist4; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
		shift
done

for APP1 in $mylist2; do
        for APP2 in $mylist3; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
		shift
done

for APP1 in $mylist2; do
        for APP2 in $mylist4; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
		shift
done
for APP1 in $mylist3; do
        for APP2 in $mylist4; do
	    cat script_base_workloads.pbs | sed -e "s/JPEG_NN/$APP1\_$APP2/g" > workloads/$APP1\_$APP2/pbs_$APP1\_$APP2.pbs
        done
		shift
done
