#!/bin/bash

for benchmark in BFS2S lulesh
do
	    cd  cache_sense/$benchmark/
	    qsub pbs_$benchmark.pbs
	    cd -
done
