#!/bin/bash


for benchmark in BFS MD QTC Reduction Scan Spmv Stencil2D Triad
do
	    cat script_base_shoc.pbs | sed -e "s/MD/$benchmark/g" > shoc/$benchmark/pbs_$benchmark.pbs

done
