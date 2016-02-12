#!/usr/bin/perl -w 

use English;

@benchmarks = (
"LUH", 
"SPMV", 
"CONS", 
"BFS", 
"SSSP", 
"HS",
"QTC", 
"TRD", 
"BH", 
"SCP",   
"SC", 
"NW");  

@file_list = (
"cache_sense/lulesh/output_lulesh.txt", 
"parboil/spmv/output_spmv.txt", 
"CUDA/CONS/output_CONS.txt", 
"lonestar/bfs/output_bfs.txt", 
"lonestar/sssp/output_sssp.txt", 
"rodinia/hotspot/output_hotspot.txt", 

"shoc/QTC/output_QTC.txt", 
"shoc/Triad/output_Triad.txt", 
"lonestar/bh/output_bh.txt", 
"CUDA/SCP/output_SCP.txt", 
"rodinia/streamcluster/output_streamcluster.txt",
"rodinia/nw/output_nw.txt"
);

$result_file = "all_results_selective.txt";

open(OUTPUT, ">$result_file") || die "Cannot open file $result_file for writing\n";

for ($j = 0; $j <= $#file_list; $j++) 
{  
	my $ipc = `grep gpu_tot_ipc $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($ipc);
	push @globalipc, $ipc;
	
	my $ins = `grep gpu_tot_sim_insn $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($ins);
	push @globalins, $ins;	
	
	my $row_locality = `grep "average row locality" $file_list[$j] | tail -n 1 | awk '\{print \$7\}'`;
	chomp($row_locality);
    push @globalrow_locality, $row_locality;
	
	my $avg_rank_one_core_side_count = `grep "DOC_CORE" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($avg_rank_one_core_side_count);
    push @globalavg_rank_one_core_side_count, $avg_rank_one_core_side_count;
	
	my $stat_avg_rank_one_count = `grep "DOC_MC" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($stat_avg_rank_one_count);
    push @globalstat_avg_rank_one_count, $stat_avg_rank_one_count;
	
	my $stat_avg_locality_count = `grep "stat_avg_locality_count" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($stat_avg_locality_count);
    push @globalstat_avg_locality_count, $stat_avg_locality_count;
	
	my $max_locality_size = `grep "max_locality_size" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($max_locality_size);
    push @globalmax_locality_size, $max_locality_size;
	
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
	
	my $averagemflatency = `grep "averagemflatency" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($averagemflatency);
    push @globalaveragemflatency, $averagemflatency;

	@dram_util = `grep "bw_util" $file_list[$j] | tail -n 6 |  awk '\{print \$14\}' |  awk -F '=' '\{print \$2\}'`;
	chomp(@dram_util);
	push @globaldram_util, [avg(\@dram_util)];
	
	my $cri_non_cri_presence = `grep "cri_non_cri_presence" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($cri_non_cri_presence);
    push @globalcri_non_cri_presence, $cri_non_cri_presence;
	
	my $scheme_cri_effectiveness = `grep "cri_picked" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($scheme_cri_effectiveness);
    push @globalscheme_cri_effectiveness, $scheme_cri_effectiveness;
	
	my $how_many_different_ranks = `grep "how_many_different_ranks" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($how_many_different_ranks);
    push @globalhow_many_different_ranks, $how_many_different_ranks;	
	
	my $SCHEME_EFFECTIVENESS = `grep "SCHEME_EFFECTIVENESS" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($SCHEME_EFFECTIVENESS);
    push @globalSCHEME_EFFECTIVENESS, $SCHEME_EFFECTIVENESS;
	
	my $core_cri_percentage = `grep "core_cri_percentage" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($core_cri_percentage);
    push @globalcore_cri_percentage, $core_cri_percentage;
	
	my $mem_cri_percentage = `grep "mem_cri_percentage" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
	chomp($mem_cri_percentage);
    push @globalmem_cri_percentage, $mem_cri_percentage;
} 
	print OUTPUT "Benchmarks \t";
	print OUTPUT "IPC\t";
	print OUTPUT "INS\t";
	print OUTPUT "RBL \t";
	print OUTPUT "DOC_CORE\t";
	print OUTPUT "DOC_MC \t";
	print OUTPUT "core_cri_percentage \t";
	print OUTPUT "mem_cri_percentage \t";
	print OUTPUT "cri_noncri \t";
	print OUTPUT "cri_picked\t";
	print OUTPUT "scheme_eff \t";

	print OUTPUT "AVGEMF \t";
	print OUTPUT "DRAM-Util \t";
	print OUTPUT "how_many_uniq_ranks \t";
	print OUTPUT "avg_locc \t";
	print OUTPUT "max_locc \t";	
	print OUTPUT "rank_1 \t";
	print OUTPUT "rank_2 \t";
	print OUTPUT "rank_3 \t";
	print OUTPUT "rank_4 \t";
	print OUTPUT "rank_5 \t";
	print OUTPUT "rank_6 \t";
	print OUTPUT "rank_7 \t";
	print OUTPUT "rank_8 \t";
	print OUTPUT "\n";

for ($k = 0;$k <= $#file_list;$k++) 
{
	print OUTPUT "$benchmarks[$k] \t";
	print OUTPUT "$globalipc[$k] \t";
	print OUTPUT "$globalins[$k] \t";
	print OUTPUT "$globalrow_locality[$k] \t";
	print OUTPUT "$globalavg_rank_one_core_side_count[$k] \t";
	print OUTPUT "$globalstat_avg_rank_one_count[$k] \t";
	print OUTPUT "$globalcore_cri_percentage[$k] \t";
	print OUTPUT "$globalmem_cri_percentage[$k] \t";
	
	print OUTPUT "$globalcri_non_cri_presence[$k] \t";	
	print OUTPUT "$globalscheme_cri_effectiveness[$k] \t";
	print OUTPUT "$globalSCHEME_EFFECTIVENESS[$k] \t";
	
	print OUTPUT "$globalaveragemflatency[$k] \t";
	print OUTPUT "$globaldram_util[$k][0] \t";
	print OUTPUT "$globalhow_many_different_ranks[$k] \t";
	print OUTPUT "$globalstat_avg_locality_count[$k] \t";
	print OUTPUT "$globalmax_locality_size[$k] \t";
	
	print OUTPUT "$globalMY_global_rank_dist_1[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_2[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_3[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_4[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_5[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_6[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_7[$k] \t";
	print OUTPUT "$globalMY_global_rank_dist_8[$k] \t";
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
