#!/bin/bash

#dmr

for benchmark in bfs bh mst sp sssp dmr 
do
	    cd  lonestar/$benchmark/
	    qsub pbs_$benchmark.pbs
	    cd -
done

