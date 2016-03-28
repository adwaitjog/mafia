#!/usr/bin/perl -w 

use English;

#use Data::Dump qw(dump);


my @apps = Readapps('apps.txt');
my @apps2 = Readapps('apps2.txt');
my @apps3 = Readapps('apps3.txt');
my @apps4 = Readapps('apps4.txt');

sub Readapps{
    
    $var = $_[0];
    open(my $fh, "<",$var) || die "Failed to open file: $!\n";
    local @array;
    while(<$fh>) {
        chomp;
        push @array, (split / /, $_);
    }
    close $fh;
    
    return @array;
}


sub Constructlist{
    my @list = @_;
    for my $i (0..$#list) {
        push @filelist, "singleapps/" . $list[$i] . "/output_". $list[$i] . ".txt"
    }
    return @filelist;
}


@benchmarks =(@apps, @apps2, @apps3, @apps4 );

#dump @benchmarks;
@file_list= Constructlist(@benchmarks);

#dump @files;

$result_file = "single_results.txt";

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
	
	my $row_locality = `grep "average row locality" $file_list[$j] |  tail -n 3 | head -n 1 | awk '\{print \$7\}'`;
	chomp($row_locality);
	push @globalrow_locality, $row_locality;
	
	my $averagemflatency = `grep "averagemflatency" $file_list[$j] |  tail -n 2 | head -n 1 |  awk '\{print \$3\}'`;
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
	
        my $L2ac_1 = `grep  "Stream 1: Misses" $file_list[$j] | tail -n  1 |
        awk '\{print \$5\}'`;
	chomp($L2ac_1);
	push @globalL2ac_1, $L2ac_1;
        
        my $L2ac_2 = `grep  "Stream 2: Misses" $file_list[$j] | tail -n  1 |
        awk '\{print \$5\}'`;
	chomp($L2ac_2);
	push @globalL2ac_2, $L2ac_2;

	my $wa = `grep global_avg_wa_app_1 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($wa);
	push @global_wa, $wa;	
	
	my $tw = `grep global_avg_tw_app_1 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($tw);
	push @global_tw, $tw;		
	

	my $wa_2 = `grep global_avg_wa_app_2 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($wa_2);
	push @global_wa_2, $wa_2;	
	
	my $tw_2  = `grep global_avg_tw_app_2 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
	chomp($tw_2 );
	push @global_tw_2 , $tw_2 ;	

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
	
	print OUTPUT "Avg-Slack-1\t";
	print OUTPUT "Avg-Occupancy-1\t";
	
	print OUTPUT "Avg-Slack-2\t";
	print OUTPUT "Avg-Occupancy-2\t";

        print OUTPUT "L2-AC-1\t";
        print OUTPUT "L2-AC-2\t";
	
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
	
	print OUTPUT "$global_wa[$k] \t";
	print OUTPUT "$global_tw[$k] \t";
	
	print OUTPUT "$global_wa_2[$k] \t";
	print OUTPUT "$global_tw_2[$k] \t";
	
        print OUTPUT "$globalL2ac_1[$k] \t";
	print OUTPUT "$globalL2ac_2[$k] \t";
	
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

