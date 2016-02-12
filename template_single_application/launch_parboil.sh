#!/bin/bash

#mm cutcp histo sad

for benchmark in spmv 
do
        cd  parboil/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done
