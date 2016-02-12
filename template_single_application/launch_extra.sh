
for benchmark in LIB MUM LPS AES BlackScholes SLA STO
do
	    cd  CUDA/$benchmark/
 	    qsub pbs_$benchmark.pbs
	    cd -
done

for benchmark in mm histo sad
do
        cd  parboil/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done

for benchmark in heartwall streamcluster lud nw
do
	cd  rodinia/$benchmark/
	qsub pbs_$benchmark.pbs
	cd -
done

for benchmark in KMNS
do
	    cd  cache_sense/$benchmark/
	    qsub pbs_$benchmark.pbs
	    cd -
done

sh launch_mars.sh
