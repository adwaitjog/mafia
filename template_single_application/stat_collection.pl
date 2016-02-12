#!/usr/bin/perl -w 

use English;
# "KMNS"
#"PVC", "PVR", "SSC",
#"MD", "QTC", 
# "LIB", "MUM"
#"heartwall", "streamcluster", "lud", "nw",
#"mm", "cutcp", "histo", "sad"
#"gups", "dgemm", 
#"ST2D", "TRD", 
#"BFS2",
#"JPEG",
#"spmv",
#"backprop", 

@benchmarks = (
"LUH", 
"RED", "SCAN", 
"LPS", "SCP", "CONS", "RAY",  "BLK",
#"bfs-l", "bh-l", "mst-l", "sp-l", "sssp-l", "dmr-l", 
"HS", "CFD",
"GAUSS");

#"cache_sense/KMNS/output_KMNS.txt", 
#"Mars/PageViewCount/output_PVC.txt", 
#"Mars/PageViewRank/output_PVR.txt", 
#"Mars/SimilarityScore/output_SSC.txt", 
#"parboil/cutcp/output_cutcp.txt",
#"parboil/histo/output_histo.txt",
#"parboil/sad/output_sad.txt",
#"nvkernels/gups/output_gups.txt",
#"nvkernels/dgemm/output_dgemm.txt",
#"rodinia/lud/output_lud.txt", 
#"rodinia/nw/output_nw.txt", 
#"rodinia/streamcluster/output_streamcluster.txt", 
#"parboil/mm/output_mm.txt",
#"rodinia/heartwall/output_heartwall.txt", 
#"shoc/MD/output_MD.txt",
#"shoc/QTC/output_QTC.txt", 
#"CUDA/LIB/output_LIB.txt",
#"cache_sense/BFS2S/output_BFS2S.txt", 
#"shoc/Stencil2D/output_Stencil2D.txt", 
#"shoc/Triad/output_Triad.txt", 
#"CUDA/JPEG/output_JPEG.txt",
#"rodinia/backprop/output_backprop.txt", 
#"parboil/spmv/output_spmv.txt",
#"lonestar/bfs/output_bfs.txt", 
#"lonestar/bh/output_bh.txt", 
#"lonestar/mst/output_mst.txt", 
#"lonestar/sp/output_sp.txt", 
#"lonestar/sssp/output_sssp.txt", 
#"lonestar/dmr/output_dmr.txt", 

@file_list = (
"cache_sense/lulesh/output_lulesh.txt", 
"shoc/Reduction/output_Reduction.txt", 
"shoc/Scan/output_Scan.txt",
"CUDA/LPS/output_LPS.txt", 
"CUDA/SCP/output_SCP.txt", 
"CUDA/CONS/output_CONS.txt", 
"CUDA/RAY/output_RAY.txt",
"CUDA/BlackScholes/output_BlackScholes.txt",
"rodinia/hotspot/output_hotspot.txt", 
"rodinia/cfd/output_cfd.txt", 
"nvkernels/gauss/output_gauss.txt"
);

$result_file = "all_results.txt";

open(OUTPUT, ">$result_file") || die "Cannot open file $result_file for writing\n";

for ($j = 0; $j <= $#file_list; $j++) 
{  
	my $ipc = `grep gpu_tot_ipc $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($ipc);
	push @globalipc, $ipc;
	
	my $memwait = `grep "total_stalls =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($memwait);
	push @globalmemwait, $memwait;	
	
	my $notabletoissue = `grep "memory_wait_time =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($notabletoissue);
	push @globalnotabletoissue, $notabletoissue;	
	
	my $idlewait = `grep "idle_wait_time =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($idlewait);
	push @globalidlewait, $idlewait;	
	
	my $smcyles = `grep "Stall_Scoreboard =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($smcyles);
	push @globalsmcyles, $smcyles;	
	
	my $smidlecyles = `grep "gpu_idle_cycles =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($smidlecyles);
	push @globalsmidlecyles, $smidlecyles;	
	
	my $underutilized = `grep "underutilized_time =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($underutilized);
	push @globalunderutilized, $underutilized;	
	
	my $crieqlocal = `grep "criticality_equals_locality =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($crieqlocal);
	push @globalcrieqlocal, $crieqlocal;	
		
        my $ins = `grep gpu_tot_sim_insn $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($ins);
	push @globalins, $ins;	
	
	my $row_locality = `grep "average row locality" $file_list[$j] | tail -n 1 | awk '\{print \$7\}'`;
	chomp($row_locality);
        push @globalrow_locality, $row_locality;
	
	my $averagemflatency = `grep "averagemflatency" $file_list[$j] |  tail -n 3 | head -n 1 |  awk '\{print \$3\}'`;
	chomp($averagemflatency);
	push @globalaveragemflatency, $averagemflatency;

	@dram_util = `grep "bw_util" $file_list[$j] | tail -n 6 |  awk '\{print \$14\}' |  awk -F '=' '\{print \$2\}'`;
	chomp(@dram_util);
	push @globaldram_util, [avg(\@dram_util)];
	
	my $MY_global_rank_dist_1 = `grep "MY_global_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($MY_global_rank_dist_1);
        push @globalMY_global_rank_dist_1, $MY_global_rank_dist_1;
	
	my $MY_global_rank_dist_2 = `grep "MY_global_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$4\}'`;
	chomp($MY_global_rank_dist_2);
        push @globalMY_global_rank_dist_2, $MY_global_rank_dist_2;
	
	my $MY_global_rank_dist_3 = `grep "MY_global_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$5\}'`;
	chomp($MY_global_rank_dist_3);
        push @globalMY_global_rank_dist_3, $MY_global_rank_dist_3;
	
	my $MY_global_rank_dist_4 = `grep "MY_global_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$6\}'`;
	chomp($MY_global_rank_dist_4);
        push @globalMY_global_rank_dist_4, $MY_global_rank_dist_4;
	
	my $MY_global_rank_dist_5 = `grep "MY_global_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$7\}'`;
	chomp($MY_global_rank_dist_5);
        push @globalMY_global_rank_dist_5, $MY_global_rank_dist_5;
	
	my $MY_global_rank_dist_6 = `grep "MY_global_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$8\}'`;
	chomp($MY_global_rank_dist_6);
        push @globalMY_global_rank_dist_6, $MY_global_rank_dist_6;
	
	my $MY_global_rank_dist_7 = `grep "MY_global_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$9\}'`;
	chomp($MY_global_rank_dist_7);
        push @globalMY_global_rank_dist_7, $MY_global_rank_dist_7;
	
	my $MY_global_rank_dist_8 = `grep "MY_global_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$10\}'`;
	chomp($MY_global_rank_dist_8);
        push @globalMY_global_rank_dist_8, $MY_global_rank_dist_8;
	
        my $MY_core_1_rank_dist_0 = `grep "core_cri_percentage =" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($MY_core_1_rank_dist_0);
        push @globalMY_core_1_rank_dist_0, $MY_core_1_rank_dist_0;
	
	my $MY_core_1_rank_dist_1 = `grep "core_cri_percentage =" $file_list[$j] | tail -n 1 |  awk '\{print \$4\}'`;
	chomp($MY_core_1_rank_dist_1);
        push @globalMY_core_1_rank_dist_1, $MY_core_1_rank_dist_1;
	
	my $MY_core_1_rank_dist_2 = `grep "core_cri_percentage =" $file_list[$j] | tail -n 1 |  awk '\{print \$5\}'`;
	chomp($MY_core_1_rank_dist_2);
        push @globalMY_core_1_rank_dist_2, $MY_core_1_rank_dist_2;
	
	my $MY_core_1_rank_dist_3 = `grep "core_cri_percentage =" $file_list[$j] | tail -n 1 |  awk '\{print \$6\}'`;
	chomp($MY_core_1_rank_dist_3);
        push @globalMY_core_1_rank_dist_3, $MY_core_1_rank_dist_3;
	
	my $MY_core_1_rank_dist_4 = `grep "core_cri_percentage =" $file_list[$j] | tail -n 1 |  awk '\{print \$7\}'`;
	chomp($MY_core_1_rank_dist_4);
        push @globalMY_core_1_rank_dist_4, $MY_core_1_rank_dist_4;
	
	my $MY_core_1_rank_dist_5 = `grep "core_cri_percentage =" $file_list[$j] | tail -n 1 |  awk '\{print \$8\}'`;
	chomp($MY_core_1_rank_dist_5);
        push @globalMY_core_1_rank_dist_5, $MY_core_1_rank_dist_5;
	
	my $MY_core_1_rank_dist_6 = `grep "core_cri_percentage =" $file_list[$j] | tail -n 1 |  awk '\{print \$9\}'`;
	chomp($MY_core_1_rank_dist_6);
        push @globalMY_core_1_rank_dist_6, $MY_core_1_rank_dist_6;
	
	my $MY_core_1_rank_dist_7 = `grep "core_cri_percentage =" $file_list[$j] | tail -n 1 |  awk '\{print \$10\}'`;
	chomp($MY_core_1_rank_dist_7);
        push @globalMY_core_1_rank_dist_7, $MY_core_1_rank_dist_7;
	
	my $MY_core_1_rank_dist_8 = `grep "core_cri_percentage =" $file_list[$j] | tail -n 1 |  awk '\{print \$11\}'`;
	chomp($MY_core_1_rank_dist_8);
        push @globalMY_core_1_rank_dist_8, $MY_core_1_rank_dist_8;
	
	my $MY_rank_diff_dist_0 = `grep "rank_diff =" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($MY_rank_diff_dist_0);
        push @globalMY_rank_diff_dist_0, $MY_rank_diff_dist_0;
	
	my $MY_rank_diff_dist_1 = `grep "rank_diff =" $file_list[$j] | tail -n 1 |  awk '\{print \$4\}'`;
	chomp($MY_rank_diff_dist_1);
        push @globalMY_rank_diff_dist_1, $MY_rank_diff_dist_1;
	
	my $MY_rank_diff_dist_2 = `grep "rank_diff =" $file_list[$j] | tail -n 1 |  awk '\{print \$5\}'`;
	chomp($MY_rank_diff_dist_2);
        push @globalMY_rank_diff_dist_2, $MY_rank_diff_dist_2;
	
	my $MY_rank_diff_dist_3 = `grep "rank_diff =" $file_list[$j] | tail -n 1 |  awk '\{print \$6\}'`;
	chomp($MY_rank_diff_dist_3);
        push @globalMY_rank_diff_dist_3, $MY_rank_diff_dist_3;
	
	my $MY_rank_diff_dist_4 = `grep "rank_diff =" $file_list[$j] | tail -n 1 |  awk '\{print \$7\}'`;
	chomp($MY_rank_diff_dist_4);
        push @globalMY_rank_diff_dist_4, $MY_rank_diff_dist_4;
	
	my $MY_rank_diff_dist_5 = `grep "rank_diff =" $file_list[$j] | tail -n 1 |  awk '\{print \$8\}'`;
	chomp($MY_rank_diff_dist_5);
        push @globalMY_rank_diff_dist_5, $MY_rank_diff_dist_5;
	
	my $MY_rank_diff_dist_6 = `grep "rank_diff =" $file_list[$j] | tail -n 1 |  awk '\{print \$9\}'`;
	chomp($MY_rank_diff_dist_6);
        push @globalMY_rank_diff_dist_6, $MY_rank_diff_dist_6;
	
	my $MY_rank_diff_dist_7 = `grep "rank_diff =" $file_list[$j] | tail -n 1 |  awk '\{print \$10\}'`;
	chomp($MY_rank_diff_dist_7);
        push @globalMY_rank_diff_dist_7, $MY_rank_diff_dist_7;
	

	my $MY_MY_cumm_rank_dist_lat_1 = `grep "MY_cumm_rank_dist_lat =" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($MY_MY_cumm_rank_dist_lat_1);
        push @globalMY_cumm_rank_dist_lat_1, $MY_MY_cumm_rank_dist_lat_1;
	
	my $MY_MY_cumm_rank_dist_lat_2 = `grep "MY_cumm_rank_dist_lat =" $file_list[$j] | tail -n 1 |  awk '\{print \$4\}'`;
	chomp($MY_MY_cumm_rank_dist_lat_2);
        push @globalMY_cumm_rank_dist_lat_2, $MY_MY_cumm_rank_dist_lat_2;
	
	my $MY_MY_cumm_rank_dist_lat_3 = `grep "MY_cumm_rank_dist_lat =" $file_list[$j] | tail -n 1 |  awk '\{print \$5\}'`;
	chomp($MY_MY_cumm_rank_dist_lat_3);
        push @globalMY_cumm_rank_dist_lat_3, $MY_MY_cumm_rank_dist_lat_3;
	
	my $MY_MY_cumm_rank_dist_lat_4 = `grep "MY_cumm_rank_dist_lat =" $file_list[$j] | tail -n 1 |  awk '\{print \$6\}'`;
	chomp($MY_MY_cumm_rank_dist_lat_4);
        push @globalMY_cumm_rank_dist_lat_4, $MY_MY_cumm_rank_dist_lat_4;
	
	my $MY_MY_cumm_rank_dist_lat_5 = `grep "MY_cumm_rank_dist_lat =" $file_list[$j] | tail -n 1 |  awk '\{print \$7\}'`;
	chomp($MY_MY_cumm_rank_dist_lat_5);
        push @globalMY_cumm_rank_dist_lat_5, $MY_MY_cumm_rank_dist_lat_5;
	
	my $MY_MY_cumm_rank_dist_lat_6 = `grep "MY_cumm_rank_dist_lat =" $file_list[$j] | tail -n 1 |  awk '\{print \$8\}'`;
	chomp($MY_MY_cumm_rank_dist_lat_6);
        push @globalMY_cumm_rank_dist_lat_6, $MY_MY_cumm_rank_dist_lat_6;
	
	my $MY_MY_cumm_rank_dist_lat_7 = `grep "MY_cumm_rank_dist_lat =" $file_list[$j] | tail -n 1 |  awk '\{print \$9\}'`;
	chomp($MY_MY_cumm_rank_dist_lat_7);
        push @globalMY_cumm_rank_dist_lat_7, $MY_MY_cumm_rank_dist_lat_7;
	
	my $MY_MY_cumm_rank_dist_lat_8 = `grep "MY_cumm_rank_dist_lat =" $file_list[$j] | tail -n 1 |  awk '\{print \$10\}'`;
	chomp($MY_MY_cumm_rank_dist_lat_8);
        push @globalMY_cumm_rank_dist_lat_8, $MY_MY_cumm_rank_dist_lat_8;
	
        my $findsd = `grep "find_sd =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($findsd);
	push @globalfindsd, $findsd;	
        
        my $findmean = `grep "find_mean =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($findmean);
	push @globalfindmean, $findmean;	
	
        my $findrank = `grep "avg_rank =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($findrank);
	push @globalfindrank, $findrank;	

        my $sdmean = `grep "sd-mean =" $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($sdmean);
	push @globalsdmean, $sdmean;	
	
        @dram_blp = `grep "blp" $file_list[$j] | tail -n 6 |  awk '\{print \$21\}' |  awk -F '=' '\{print \$2\}'`;
	chomp(@dram_blp);
	push @globaldram_blp, [avg(\@dram_blp)];
} 
	print OUTPUT "Benchmarks \t";
	print OUTPUT "IPC\t";
	print OUTPUT "TotWait\t";
	print OUTPUT "MemWait\t";
	print OUTPUT "IdleWait\t";
	print OUTPUT "StallScore\t";
	print OUTPUT "SmIdlecycles\t";
	print OUTPUT "Underutilized\t";
	print OUTPUT "cri_equals_loc\t";
	print OUTPUT "INS\t";
	print OUTPUT "RBL \t";
	print OUTPUT "AVGEMF \t";
	print OUTPUT "DRAM-Util \t";

	print OUTPUT "pcc_rank_0 \t";
	print OUTPUT "pcc_rank_1 \t";
	print OUTPUT "pcc_rank_2 \t";
	print OUTPUT "pcc_rank_3 \t";
	print OUTPUT "pcc_rank_4 \t";
	print OUTPUT "pcc_rank_5 \t";
	print OUTPUT "pcc_rank_6 \t";
	print OUTPUT "pcc_rank_7 \t";
	print OUTPUT "pcc_rank_8 \t";
	
	print OUTPUT "r_rank_1 \t";
	print OUTPUT "r_rank_2 \t";
	print OUTPUT "r_rank_3 \t";
	print OUTPUT "r_rank_4 \t";
	print OUTPUT "r_rank_5 \t";
	print OUTPUT "r_rank_6 \t";
	print OUTPUT "r_rank_7 \t";
	print OUTPUT "r_rank_8 \t";
	
	print OUTPUT "diffr0 \t";
	print OUTPUT "diffr1 \t";
	print OUTPUT "diffr2 \t";
	print OUTPUT "diffr3 \t";
	print OUTPUT "diffr4 \t";
	print OUTPUT "diffr5 \t";
	print OUTPUT "diffr6 \t";
	print OUTPUT "diffr7 \t";
	
	print OUTPUT "rank_1_lat \t";
	print OUTPUT "rank_2_lat \t";
	print OUTPUT "rank_3_lat \t";
	print OUTPUT "rank_4_lat \t";
	print OUTPUT "rank_5_lat \t";
	print OUTPUT "rank_6_lat \t";
	print OUTPUT "rank_7_lat \t";
	print OUTPUT "rank_8_lat \t";
	
        print OUTPUT "sd \t";
	print OUTPUT "mean \t";
	print OUTPUT "rank \t";
	print OUTPUT "blp \t";
        print OUTPUT "sdmean\t";
	
	print OUTPUT "\n";
	
for ($k = 0;$k <= $#file_list;$k++) 
{
	print OUTPUT "$benchmarks[$k] \t";
	print OUTPUT "$globalipc[$k] \t";
	print OUTPUT "$globalmemwait[$k] \t";
	print OUTPUT "$globalnotabletoissue[$k] \t";

	print OUTPUT "$globalidlewait[$k] \t";
	print OUTPUT "$globalsmcyles[$k] \t";
	print OUTPUT "$globalsmidlecyles[$k] \t";
	print OUTPUT "$globalunderutilized[$k] \t";
	print OUTPUT "$globalcrieqlocal[$k] \t";

	print OUTPUT "$globalins[$k] \t";
	print OUTPUT "$globalrow_locality[$k] \t";
	print OUTPUT "$globalaveragemflatency[$k] \t";
	print OUTPUT "$globaldram_util[$k][0] \t";

	print OUTPUT "$globalMY_core_1_rank_dist_0[$k] \t";
	print OUTPUT "$globalMY_core_1_rank_dist_1[$k] \t";
	print OUTPUT "$globalMY_core_1_rank_dist_2[$k] \t";
	print OUTPUT "$globalMY_core_1_rank_dist_3[$k] \t";
	print OUTPUT "$globalMY_core_1_rank_dist_4[$k] \t";
	print OUTPUT "$globalMY_core_1_rank_dist_5[$k] \t";
	print OUTPUT "$globalMY_core_1_rank_dist_6[$k] \t";
	print OUTPUT "$globalMY_core_1_rank_dist_7[$k] \t";
	print OUTPUT "$globalMY_core_1_rank_dist_8[$k] \t";
	
	print OUTPUT "$globalMY_global_rank_dist_1[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_2[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_3[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_4[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_5[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_6[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_7[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_8[$k] \t";
	
	print OUTPUT "$globalMY_rank_diff_dist_0[$k] \t";
	print OUTPUT "$globalMY_rank_diff_dist_1[$k] \t";
	print OUTPUT "$globalMY_rank_diff_dist_2[$k] \t";
	print OUTPUT "$globalMY_rank_diff_dist_3[$k] \t";
	print OUTPUT "$globalMY_rank_diff_dist_4[$k] \t";
	print OUTPUT "$globalMY_rank_diff_dist_5[$k] \t";
	print OUTPUT "$globalMY_rank_diff_dist_6[$k] \t";
	print OUTPUT "$globalMY_rank_diff_dist_7[$k] \t";
	
	print OUTPUT "$globalMY_cumm_rank_dist_lat_1[$k] \t";
	print OUTPUT "$globalMY_cumm_rank_dist_lat_2[$k] \t";
	print OUTPUT "$globalMY_cumm_rank_dist_lat_3[$k] \t";
	print OUTPUT "$globalMY_cumm_rank_dist_lat_4[$k] \t";
	print OUTPUT "$globalMY_cumm_rank_dist_lat_5[$k] \t";
	print OUTPUT "$globalMY_cumm_rank_dist_lat_6[$k] \t";
	print OUTPUT "$globalMY_cumm_rank_dist_lat_7[$k] \t";
	print OUTPUT "$globalMY_cumm_rank_dist_lat_8[$k] \t";

	print OUTPUT "$globalfindsd[$k] \t";
	print OUTPUT "$globalfindmean[$k] \t";
	print OUTPUT "$globalfindrank[$k] \t";
	print OUTPUT "$globaldram_blp[$k][0] \t";
	print OUTPUT "$globalsdmean[$k] \t";
        
	print OUTPUT "\n";
}

sub avg {
	@_ == 1 or die ('Sub usage: $avg = avg(\@array);');
	my ($array_ref) = @_;
	my $sum;
	my $count = scalar @$array_ref;
        if ($count == 0) {
                return 0;
        }
	foreach (@$array_ref) { $sum += $_; }
	return $sum / $count;
}

sub max {
	@_ == 1 or die ('Sub usage: $max = max(\@array);');
	my ($array_ref) = @_;
	my $maxval = -999999999999999999;
	foreach (@$array_ref)
	{
		if ( $maxval < $_ )
		{
			$maxval = $_;
		}
	}
	return $maxval;
}

sub sum {
	@_ == 1 or die ('Sub usage: $sum = sum(\@array);');
	my ($array_ref) = @_;
	my $sum;
	foreach (@$array_ref) { $sum += $_; }
	return $sum;
}
