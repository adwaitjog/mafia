#!/bin/sh

mkdir workloads
cd workloads
GPGPUSIM_CONFIG=$1

mylist=`cat ../apps.txt`
set -- $mylist

#ln -s $applications/pthread_benchmark/* .

for APP1; do
        shift
        for APP2; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
done
mylist2=`cat ../apps2.txt`
set -- $mylist2

for APP1; do
        shift
        for APP2; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
done

mylist3=`cat ../apps3.txt`
set -- $mylist3

for APP1; do
        shift
        for APP2; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
done

mylist4=`cat ../apps4.txt`
set -- $mylist4

for APP1; do
        shift
        for APP2; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
done

for APP1 in $mylist; do
        for APP2 in $mylist2; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
		shift
done

for APP1 in $mylist; do
        for APP2 in $mylist3; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
		shift
done

for APP1 in $mylist; do
        for APP2 in $mylist4; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
		shift
done

for APP1 in $mylist2; do
        for APP2 in $mylist3; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
		shift
done

for APP1 in $mylist2; do
        for APP2 in $mylist4; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
		shift
done
for APP1 in $mylist3; do
        for APP2 in $mylist4; do
                mkdir $APP1\_$APP2
                cd $APP1\_$APP2
                ln -s $applications/pthread_benchmark/$APP1 .
                ln -s $applications/pthread_benchmark/$APP2 .
                ln -s $applications/pthread_benchmark/gpgpu_ptx_sim__mergedapps .
                ln -s $applications/pthread_benchmark/run_scripts/mainscript_$APP1\_$APP2 .
                cd ../
        done
		shift
done
cd ../
sh gen_pbs_workloads.sh

if [ "x$GPGPUSIM_CONFIG" = "x" ]; then 
    echo "Usage: $0 <GPGPU-Sim Config Name | --cleanup>"
    exit 0
fi

if [ "x$GPGPUSIM_ROOT" = "x" ]; then 
    GPGPUSIM_ROOT="$PWD/.."
fi

BENCHMARKS=`ls workloads | sed 's/\([^ ]\+\)/\.\/workloads\/\1/'`

GPU_CONFIG_FILE=$GPGPUSIM_ROOT/configs/$GPGPUSIM_CONFIG/gpgpusim.config
if [ -f $GPU_CONFIG_FILE ]; then
    echo "Found GPGPU-Sim config file: $GPU_CONFIG_FILE"
else
    echo "Unknown config: $GPGPUSIM_CONFIG"
    exit 0
fi

ICNT_CONFIG=`awk '/-inter_config_file/ { print $2 }' $GPU_CONFIG_FILE`
ICNT_CONFIG=$GPGPUSIM_ROOT/configs/$GPGPUSIM_CONFIG/$ICNT_CONFIG
if [ -f $GPU_CONFIG_FILE ]; then
    echo "Interconnection config file detected: $ICNT_CONFIG"
else
    echo "Interconnection config file not found: $ICNT_CONFIG"
    exit 0
fi

POWER_CONFIG=`awk '/-gpuwattch_xml_file/ { print $2 }' $GPU_CONFIG_FILE`
POWER_CONFIG=$GPGPUSIM_ROOT/configs/$GPGPUSIM_CONFIG/$POWER_CONFIG
if [ -f $GPU_CONFIG_FILE ]; then
    echo "Power config file detected: $POWER_CONFIG"
else
    echo "Power config file not found: $POWER_CONFIG"
    exit 0
fi

for BMK in $BENCHMARKS; do
    if [ -f $BMK/gpgpusim.config ]; then
        echo "Existing symbolic-links to config found in $BMK! Skipping... "
    else
        echo "Adding symbolic-links to configuration files for $BMK:"
        ln -v -s $GPU_CONFIG_FILE $BMK
        ln -v -s $ICNT_CONFIG $BMK
		ln -v -s $POWER_CONFIG $BMK
    fi
done
