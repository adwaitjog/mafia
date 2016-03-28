#!/usr/bin/perl -w 

use English;

@benchmarks = (
"LUH", "BFS2", "KMNS",
"MD", "QTC", "ST2D", "TRD", "RED", "SCAN", 
"MUM", "FWT", "SCP", "CONS", "NN", "JPEG", "LIB", "RAY", "BLK", "LPS",
"BFSL", "BHL", "MSTL", "SPL", "SSSPL", "DMRL", 
"BP", "HS","HW", "SC", "LUD", "NW", "CFD",
"MM", "SPMV", "CUTCP", "HISTO", "SAD", "FFT",
"GUPS", "DGEMM", "GAUSS", "HIST", "3DS",
"PVC", "PVR", "SSC", "IIX"
);

@file_list = (
"cache_sense/lulesh/output_lulesh.txt", 
"cache_sense/BFS2S/output_BFS2S.txt", 
"cache_sense/KMNS/output_KMNS.txt", 
"shoc/MD/output_MD.txt",
"shoc/QTC/output_QTC.txt", 
"shoc/Stencil2D/output_Stencil2D.txt", 
"shoc/Triad/output_Triad.txt", 
"shoc/Reduction/output_Reduction.txt", 
"shoc/Scan/output_Scan.txt",
"CUDA/MUM/output_MUM.txt",
"CUDA/FWT/output_FWT.txt", 
"CUDA/SCP/output_SCP.txt", 
"CUDA/CONS/output_CONS.txt", 
"CUDA/NN/output_NN.txt",
"CUDA/JPEG/output_JPEG.txt",
"CUDA/LIB/output_LIB.txt",
"CUDA/RAY/output_RAY.txt",
"CUDA/BlackScholes/output_BlackScholes.txt",
"CUDA/LPS/output_LPS.txt",
"lonestar/bfs/output_bfs.txt", 
"lonestar/bh/output_bh.txt", 
"lonestar/mst/output_mst.txt", 
"lonestar/sp/output_sp.txt", 
"lonestar/sssp/output_sssp.txt", 
"lonestar/dmr/output_dmr.txt", 
"rodinia/backprop/output_backprop.txt", 
"rodinia/hotspot/output_hotspot.txt", 
"rodinia/heartwall/output_heartwall.txt", 
"rodinia/streamcluster/output_streamcluster.txt", 
"rodinia/lud/output_lud.txt", 
"rodinia/nw/output_nw.txt", 
"rodinia/cfd/output_cfd.txt", 
"parboil/mm/output_mm.txt",
"parboil/spmv/output_spmv.txt",
"parboil/cutcp/output_cutcp.txt",
"parboil/histo/output_histo.txt",
"parboil/sad/output_sad.txt",
"parboil/fft/output_fft.txt",
"nvkernels/gups/output_gups.txt",
"nvkernels/dgemm/output_dgemm.txt",
"nvkernels/gauss/output_gauss.txt",
"nvkernels/hist/output_hist.txt",
"nvkernels/rtm/output_rtm.txt",
"Mars/PageViewCount/output_PVC.txt", 
"Mars/PageViewRank/output_PVR.txt", 
"Mars/SimilarityScore/output_SSC.txt",
"Mars/InvertedIndex/output_IIX.txt"
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
	
	my @bw_dist_1 = `grep "bw_dist" $file_list[$j] | tail -n 6 |  awk '\{print \$3\}'`;
	chomp(@bw_dist_1);
	push @globalbw_dist_1, [avg(\@bw_dist_1)];
	
	my @bw_dist_2 = `grep "bw_dist" $file_list[$j] | tail -n 6 |  awk '\{print \$4\}'`;
	chomp(@bw_dist_2);
	push @globalbw_dist_2, [avg(\@bw_dist_2)];
	
	my @bw_dist_3 = `grep "bw_dist" $file_list[$j] | tail -n 6 |  awk '\{print \$5\}'`;
	chomp(@bw_dist_3);
	push @globalbw_dist_3, [avg(\@bw_dist_3)];
	
	my @bw_dist_4 = `grep "bw_dist" $file_list[$j] | tail -n 6 |  awk '\{print \$6\}'`;
	chomp(@bw_dist_4);
	push @globalbw_dist_4, [avg(\@bw_dist_4)];
	
	my $MY_app_1_rank_dist_0 = `grep "^app_1_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($MY_app_1_rank_dist_0);
	push @globalMY_app_1_rank_dist_0, $MY_app_1_rank_dist_0;
	
	my $MY_app_1_rank_dist_1 = `grep "^app_1_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$4\}'`;
	chomp($MY_app_1_rank_dist_1);
	push @globalMY_app_1_rank_dist_1, $MY_app_1_rank_dist_1;
	
	my $MY_app_1_rank_dist_2 = `grep "^app_1_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$5\}'`;
	chomp($MY_app_1_rank_dist_2);
	push @globalMY_app_1_rank_dist_2, $MY_app_1_rank_dist_2;
	
	my $MY_app_1_rank_dist_3 = `grep "^app_1_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$6\}'`;
	chomp($MY_app_1_rank_dist_3);
	 push @globalMY_app_1_rank_dist_3, $MY_app_1_rank_dist_3;
	
	my $MY_app_1_rank_dist_4 = `grep "^app_1_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$7\}'`;
	chomp($MY_app_1_rank_dist_4);
	push @globalMY_app_1_rank_dist_4, $MY_app_1_rank_dist_4;
	
	my $MY_app_1_rank_dist_5 = `grep "^app_1_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$8\}'`;
	chomp($MY_app_1_rank_dist_5);
	push @globalMY_app_1_rank_dist_5, $MY_app_1_rank_dist_5;
	
	my $MY_app_1_rank_dist_6 = `grep "^app_1_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$9\}'`;
	chomp($MY_app_1_rank_dist_6);
	push @globalMY_app_1_rank_dist_6, $MY_app_1_rank_dist_6;
	
	my $MY_app_1_rank_dist_7 = `grep "^app_1_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$10\}'`;
	chomp($MY_app_1_rank_dist_7);
	push @globalMY_app_1_rank_dist_7, $MY_app_1_rank_dist_7;
	
	my $MY_app_1_rank_dist_8 = `grep "^app_1_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$11\}'`;
	chomp($MY_app_1_rank_dist_8);
	push @globalMY_app_1_rank_dist_8, $MY_app_1_rank_dist_8;
		
	my $Stream_1_L2missrate = `grep  "Stream 1: L2 Cache Miss Rate" $file_list[$j] | tail -n  1 | awk '\{print \$8\}'`;
	chomp($Stream_1_L2missrate);
	push @globalStream_1_L2missrate, $Stream_1_L2missrate;
	
	my $Stream_2_L2missrate = `grep  "Stream 2: L2 Cache Miss Rate" $file_list[$j] | tail -n  1 | awk '\{print \$8\}'`;
	chomp($Stream_2_L2missrate);
	push @globalStream_2_L2missrate, $Stream_2_L2missrate;
	
	my $L2missrate = `grep  "L2 Cache Total Miss Rate" $file_list[$j] | tail -n  1 | awk '\{print \$7\}'`;
	chomp($L2missrate);
	push @globalL2missrate, $L2missrate;
} 
	print OUTPUT "Benchmarks \t";
	print OUTPUT "IPC\t";
	print OUTPUT "TotStalls\t";
	print OUTPUT "INS\t";
	print OUTPUT "RBL \t";
	print OUTPUT "AVGEMF \t";
	print OUTPUT "DRAM-Util \t";

	print OUTPUT "R0 \t";
	print OUTPUT "R1 \t";
	print OUTPUT "R2 \t";
	print OUTPUT "R3 \t";
	print OUTPUT "R4 \t";
	print OUTPUT "R5 \t";
	print OUTPUT "R6 \t";
	print OUTPUT "R7 \t";
	print OUTPUT "R8 \t";
	
	print OUTPUT "App1-BW \t";
	print OUTPUT "App2-BW\t";
	print OUTPUT "Waste-BW \t";
	print OUTPUT "Idle-BW \t";
	
	print OUTPUT "L2-Miss-Rate-1\t";
	print OUTPUT "L2-Miss-Rate-2\t";
	print OUTPUT "L2-Miss-Rate\t";
	print OUTPUT "\n";
	
for ($k = 0;$k <= $#file_list;$k++) 
{
	print OUTPUT "$benchmarks[$k] \t";
	print OUTPUT "$globalipc[$k] \t";
	print OUTPUT "$globalmemwait[$k] \t";

	print OUTPUT "$globalins[$k] \t";
	print OUTPUT "$globalrow_locality[$k] \t";
	print OUTPUT "$globalaveragemflatency[$k] \t";
	print OUTPUT "$globaldram_util[$k][0] \t";

	print OUTPUT "$globalMY_app_1_rank_dist_0[$k] \t";
	print OUTPUT "$globalMY_app_1_rank_dist_1[$k] \t";
	print OUTPUT "$globalMY_app_1_rank_dist_2[$k] \t";
	print OUTPUT "$globalMY_app_1_rank_dist_3[$k] \t";
	print OUTPUT "$globalMY_app_1_rank_dist_4[$k] \t";
	print OUTPUT "$globalMY_app_1_rank_dist_5[$k] \t";
	print OUTPUT "$globalMY_app_1_rank_dist_6[$k] \t";
	print OUTPUT "$globalMY_app_1_rank_dist_7[$k] \t";
	print OUTPUT "$globalMY_app_1_rank_dist_8[$k] \t";
	
	print OUTPUT "$globalbw_dist_1[$k][0] \t";
	print OUTPUT "$globalbw_dist_2[$k][0] \t";
	print OUTPUT "$globalbw_dist_3[$k][0] \t";
	print OUTPUT "$globalbw_dist_4[$k][0] \t";
	
	print OUTPUT "$globalStream_1_L2missrate[$k] \t";
	print OUTPUT "$globalStream_2_L2missrate[$k] \t";
	print OUTPUT "$globalL2missrate[$k] \t";
	
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
