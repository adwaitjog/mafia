#!/bin/bash

for benchmark in backprop hotspot 
do
	    cat script_base_rodinia_1.pbs | sed -e "s/hotspot/$benchmark/g" > rodinia/$benchmark/pbs_$benchmark.pbs

done

for benchmark in pf_naive pf_float bfs heartwall cfd streamcluster nw lud srad_v1 srad_v2 pathfinder myocyte lavaMD gaussian b+tree
do
	    cat script_base_rodinia_2.pbs | sed -e "s/nw/$benchmark/g" > rodinia/$benchmark/pbs_$benchmark.pbs

done


