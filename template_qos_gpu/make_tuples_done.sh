#!/bin/bash

function launch {
    if  grep -wq $2 apps_run.txt
    then
        echo $1 >> tuples_done.txt	
    elif grep -wq $3 apps_run.txt
    then
        echo $1 >> tuples_done.txt	
    fi
}

mylist=`cat apps.txt`
set -- $mylist

touch tuples_done.txt
rm tuples_done.txt
touch tuples_done.txt

for APP1; do
        shift
        for APP2; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
done

mylist2=`cat apps2.txt`
set -- $mylist2

for APP1; do
        shift
        for APP2; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
done

mylist3=`cat apps3.txt`
set -- $mylist3

for APP1; do
        shift
        for APP2; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
done

mylist4=`cat apps4.txt`
set -- $mylist4

for APP1; do
        shift
        for APP2; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
done
for APP1 in $mylist; do
        for APP2 in $mylist2; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
		shift
done
for APP1 in $mylist; do
        for APP2 in $mylist3; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
		shift
done

for APP1 in $mylist; do
        for APP2 in $mylist4; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
		shift
done

for APP1 in $mylist2; do
        for APP2 in $mylist3; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
		shift
done

for APP1 in $mylist2; do
        for APP2 in $mylist4; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
		shift
done
for APP1 in $mylist3; do
        for APP2 in $mylist4; do
            launch $APP1\_$APP2 $APP2 $APP1
        done
		shift
done
