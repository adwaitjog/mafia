#!/bin/bash

for benchmark in BFS2 KMN
do
	cat script_base_cache_sense.pbs | sed -e "s/BFS2/$benchmark/g" > CUDA/$benchmark/pbs_$benchmark.pbs
done
