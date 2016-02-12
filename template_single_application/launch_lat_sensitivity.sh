#!/bin/bash

for benchmark in lulesh
do
	cd  cache_sense/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done

for benchmark in spmv
do
    cd  parboil/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done

for benchmark in SCP CONS
do
    cd  CUDA/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done

for benchmark in QTC Triad 
do
    cd  shoc/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done

for benchmark in bfs bh sssp
do
    cd  lonestar/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done

for benchmark in hotspot streamcluster nw 
do
	cd  rodinia/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done

