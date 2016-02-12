#!/bin/bash

for benchmark in AES BlackScholes CONS FWT JPEG NQU RAY SCP STO  
do
	    cat script_base_CUDA_1.pbs | sed -e "s/JPEG/$benchmark/g" > CUDA/$benchmark/pbs_$benchmark.pbs
done

for benchmark in LIB LPS MUM NN SLA TRA kmeans BFS
do
	    cat script_base_CUDA_2.pbs | sed -e "s/kmeans/$benchmark/g" > CUDA/$benchmark/pbs_$benchmark.pbs
done
