#!/bin/bash

# MD QTC 
for benchmark in Stencil2D Triad Reduction Scan 
do
  	cd  shoc/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done
