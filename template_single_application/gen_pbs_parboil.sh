#!/bin/bash

# fft tpacf
for benchmark in spmv 
do
	cat script_base_parboil_1.pbs | sed -e "s/spmv/$benchmark/g" > parboil/$benchmark/pbs_$benchmark.pbs
done

for benchmark in cutcp histo mm sad 
do
	cat script_base_parboil_2.pbs | sed -e "s/mm/$benchmark/g" > parboil/$benchmark/pbs_$benchmark.pbs
done
