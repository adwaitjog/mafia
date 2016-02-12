#!/bin/bash

#NN MUM

for benchmark in LIB RAY 
do
	    cd  CUDA/$benchmark/
 	    qsub pbs_$benchmark.pbs
	    cd -
done
