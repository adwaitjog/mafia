#!/bin/bash

for benchmark in gups dgemm rtm hist gauss
do
	cat script_base_nvkernels.pbs | sed -e "s/gups/$benchmark/g" > nvkernels/$benchmark/pbs_$benchmark.pbs
done
