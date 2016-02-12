#!/bin/bash

#gups dgemm hist

for benchmark in gauss
do
	    cd  nvkernels/$benchmark/
	    qsub pbs_$benchmark.pbs
	    cd -
done

