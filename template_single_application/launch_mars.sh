#!/bin/bash

for benchmark in PageViewCount PageViewRank SimilarityScore 
do
	    cd  Mars/$benchmark/
	    qsub pbs_$benchmark.pbs
	    cd -
done
