#!/bin/bash

#NN LIB
for benchmark in LPS SCP CONS RAY JPEG BlackScholes 
do
	    cd  CUDA/$benchmark/
 	    qsub pbs_$benchmark.pbs
	    cd -
done
