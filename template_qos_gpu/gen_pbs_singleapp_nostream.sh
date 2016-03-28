#!/bin/bash

mylist=`cat apps.txt`
set -- $mylist


for benchmark; do

	    cat script_base_singleapp_nostream.pbs | sed -e "s/JPEG_NSTR/$benchmark\_NoStream/g" > singleapps_nostream/$benchmark\_NoStream/pbs_$benchmark\_NoStream.pbs
done

mylist2=`cat apps2.txt`
set -- $mylist2


for benchmark; do

	    cat script_base_singleapp_nostream.pbs | sed -e "s/JPEG_NSTR/$benchmark\_NoStream/g" > singleapps_nostream/$benchmark\_NoStream/pbs_$benchmark\_NoStream.pbs
done

mylist3=`cat apps3.txt`
set -- $mylist3


for benchmark; do

	    cat script_base_singleapp_nostream.pbs | sed -e "s/JPEG_NSTR/$benchmark\_NoStream/g" > singleapps_nostream/$benchmark\_NoStream/pbs_$benchmark\_NoStream.pbs
done


mylist4=`cat apps4.txt`
set -- $mylist4


for benchmark; do

	    cat script_base_singleapp_nostream.pbs | sed -e "s/JPEG_NSTR/$benchmark\_NoStream/g" > singleapps_nostream/$benchmark\_NoStream/pbs_$benchmark\_NoStream.pbs
done