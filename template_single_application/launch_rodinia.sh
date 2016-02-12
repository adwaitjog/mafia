#!/bin/bash

# heartwall streamcluster lud nw cfd

for benchmark in backprop hotspot cfd
do
	cd  rodinia/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done
