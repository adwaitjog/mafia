#!/bin/bash

for benchmark in BFS2S KMNS lulesh
do
	    cd  cache_sense/$benchmark/
            rm *.txt
	    cd -
done

for benchmark in MUM FWT SCP CONS NN JPEG LIB MUM LPS AES BlackScholes SLA STO 
do
	    cd  CUDA/$benchmark/
            rm *.txt
	    cd -
done

for benchmark in lulesh
do
	cd  cache_sense/$benchmark/
            rm *.txt
	cd -
done

for benchmark in spmv
do
    cd  parboil/$benchmark/
            rm *.txt
	cd -
done

for benchmark in SCP CONS RAY
do
        cd  CUDA/$benchmark/
            rm *.txt
	cd -
done

for benchmark in QTC Triad 
do
    cd  shoc/$benchmark/
            rm *.txt
	cd -
done

for benchmark in bfs bh sssp
do
    cd  lonestar/$benchmark/
            rm *.txt
	cd -
done

for benchmark in hotspot streamcluster nw 
do
	cd  rodinia/$benchmark/
            rm *.txt
	cd -
done

for benchmark in bfs bh mst sp sssp dmr
do
	    cd  lonestar/$benchmark/
            rm *.txt
	    cd -
done

for benchmark in PageViewCount PageViewRank SimilarityScore 
do
	    cd  Mars/$benchmark/
            rm *.txt
	    cd -
done

for benchmark in gups dgemm hist gauss
do
	    cd  nvkernels/$benchmark/
            rm *.txt
	    cd -
done

for benchmark in mm spmv cutcp histo sad 
do
        cd  parboil/$benchmark/
            rm *.txt
	cd -
done

for benchmark in backprop hotspot heartwall streamcluster lud nw cfd 
do
	cd  rodinia/$benchmark/
            rm *.txt
	cd -
done

for benchmark in MD QTC Stencil2D Triad Reduction Scan Spmv
do
  	     cd  shoc/$benchmark/
            rm *.txt
	cd -
done
