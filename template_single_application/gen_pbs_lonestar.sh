#!/bin/bash

for benchmark in bfs bh dmr pta
do
	cat script_base_lonestar_1.pbs | sed -e "s/bfs/$benchmark/g" > lonestar/$benchmark/pbs_$benchmark.pbs
done

for benchmark in mst sp
do
	cat script_base_lonestar_2.pbs | sed -e "s/bfs/$benchmark/g" > lonestar/$benchmark/pbs_$benchmark.pbs
done

for benchmark in sssp
do
	cat script_base_lonestar_3.pbs | sed -e "s/bfs/$benchmark/g" > lonestar/$benchmark/pbs_$benchmark.pbs
done
