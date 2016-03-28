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

sub Combination{
    my @list = @_;
    local @result;
    foreach my $a (0..$#list) {
        foreach my $b ($a+1..$#list) {
            push @result, join("_", $list[$a], $list[$b]);
        }
    }
    return @result;
}

sub Product{
    my ($ref_list1, $ref_list2) = @_;
    local @result;
    print("The first array is  @{$ref_list1}.\n");
    print("The second array is  @{$ref_list2}.\n");
    foreach my $a (@{$ref_list1}){
        foreach my $b (@{$ref_list2}) {
            push @result, join("_", $a, $b);
        }
    }
    return @result;
}

sub Constructlist{
    my @list = @_;
    local @filelist;
    for my $i (0..$#list) {
        push @filelist, "workloads/" . $list[$i] . "/app1_app2.txt"
    }
    return @filelist;
}

sub file_exists {
   my ($qfn) = @_;
   my $rv = -e $qfn;
   die "Unable to determine if file exists: $!"
      if !defined($rv) && !$!{ENOENT};
   return $rv;
}

#@benchmarks_complete =( Combination(@apps), Combination(@apps2), Combination(@apps3), Combination(@apps4),Product(\@apps, \@apps2),Product(\@apps, \@apps3),Product(\@apps, \@apps4), Product(\@apps2, \@apps3),Product(\@apps2, \@apps4), Product(\@apps3, \@apps4));

#@complete_filelist= Constructlist(@benchmarks_complete);

my @bench_names_want = (Readapps('tuples_done.txt'));
my @tuples_want = (Constructlist(Readapps('tuples_done.txt')));

@file_list = @tuples_want;
@benchmarks = @bench_names_want;

$result_file = "all_results_selected.txt";
$sing_apps = "single_results.txt";

open(OUTPUT, ">$result_file") || die "Cannot open file $result_file for writing\n";

for ($j = 0; $j <= $#file_list; $j++)
{
    my @app_names = split(/_/, $benchmarks[$j]);
    my $app1_name = $app_names[0];
    my $app2_name = $app_names[1];
    
    #push @app2, $app2_name;
    #push @app1, $app1_name;
    
    #print "$app1_name\n";
    #print "$app2_name\n";
	
	#print "$file_list[$j]";
	my $sing_ipc1 = `grep -w $app1_name $sing_apps | awk '\{print \$2\}'`;
	my $sing_ipc2 = `grep -w $app2_name $sing_apps | awk '\{print \$2\}'`;
	
	#print "$sing_ipc1 ";
	#print "$sing_ipc2\n";
	#my $sing_ipc1 = 1000;
	#my $sing_ipc2 = 1000;
	chomp($sing_ipc1);
	chomp($sing_ipc2);
	
	push @sing_ipc1s, $sing_ipc1;
	push @sing_ipc2s, $sing_ipc2;
	
	#if (-e "$file_list[$j]") {
    
    my $app = `grep statistics $file_list[$j] | head -n 1 | awk '\{print \$7\}'`;
    chomp($app);
    
    my $ipc1;
    my $ipc2;
    
    my $slowdown1 ;
    my $slowdown2 ;
    
    my $wa;
    my $tw;
    
    my $wa2;
    my $tw2;
    
    
    if($app eq "2"){
        $ipc2 = `grep gpu_ipc_2 $file_list[$j] | head -n 1 | awk '\{print \$3\}'`;
        $ipc1 = `grep gpu_ipc_1 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
        
        $slowdown2 = `grep gpu_ipc_2 $file_list[$j] | head -n 1 | awk '\{print \$3\}'`;
        $slowdown1 = `grep gpu_ipc_1 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
        
        $wa2 = `grep global_avg_wa_app_2 $file_list[$j] | head -n 1 | awk '\{print \$3\}'`;
        $wa = `grep global_avg_wa_app_1 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
        
        $tw2 = `grep global_avg_tw_app_2 $file_list[$j] | head -n 1 | awk '\{print \$3\}'`;
        $tw = `grep global_avg_tw_app_1 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
        
    }
    else{
        $ipc2 = `grep gpu_ipc_2 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
        $ipc1 = `grep gpu_ipc_1 $file_list[$j] | head -n 1 | awk '\{print \$3\}'`;
        
        $slowdown2 = `grep gpu_ipc_2 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
        $slowdown1 = `grep gpu_ipc_1 $file_list[$j] | head -n 1 | awk '\{print \$3\}'`;
        
        $wa2 = `grep global_avg_wa_app_2 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
        $wa = `grep global_avg_wa_app_1 $file_list[$j] | head -n 1 | awk '\{print \$3\}'`;
        
        $tw2 = `grep global_avg_tw_app_2 $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
        $tw = `grep global_avg_tw_app_1 $file_list[$j] | head -n 1 | awk '\{print \$3\}'`;
    }
    
    
    chomp($wa);
    chomp($tw);
    chomp($wa2);
    chomp($tw2 );
    
    push @global_wa, $wa;
    push @global_tw, $tw;
    push @global_wa_2, $wa2;
    push @global_tw_2 , $tw2 ;
    
    chomp($ipc1);
    chomp($ipc2);
    
    push @ipc_app1, $ipc1;
    push @ipc_app2, $ipc2;
    
    if (length($ipc1)) {
        $slowdown1 = $ipc1 / $sing_ipc1;
    }
    
    if (length($ipc2)) {
        $slowdown2 = $ipc2 / $sing_ipc2;
    }
    
    my $speedup;
    
    if (length($slowdown1)) {
        if (length($slowdown2)) {
            $speedup = $slowdown1 + $slowdown2;
        }
    }
    
    my $throughput = 0;
    
    
    if (length($ipc1)) {
        if (length($ipc2)) {
            $throughput = $ipc1 + $ipc2;
        }
    }
    
    my @slowdown_ar;
    
    if (length($slowdown1)) {
        if (length($slowdown2)) {
            @slowdown_ar = ($slowdown1 / $slowdown2 , $slowdown2 / $slowdown1);
        }
    }
    
    my $fairness_index;
    $fairness_index = max(\@slowdown_ar );
    
    push @slowdown1_ar, $slowdown1;
    push @slowdown2_ar, $slowdown2;
    
    push @speedups, $speedup;
    push @throughputs, $throughput;
    push @fair_indexes, $fairness_index;
    
    my $row_locality_1 = `grep "average row locality_1" $file_list[$j] |  tail -n 1 | awk '\{print \$7\}'`;
    chomp($row_locality_1);
    push @globalrow_locality_1, $row_locality_1;
    
    my $row_locality_2 = `grep "average row locality_2" $file_list[$j] |  tail -n 1 | awk '\{print \$7\}'`;
    chomp($row_locality_2);
    push @globalrow_locality_2, $row_locality_2;
    
    my $averagemflatency_1 = `grep "averagemflatency_1" $file_list[$j] |  tail -n 1 | awk '\{print \$3\}'`;
    chomp($averagemflatency_1);
    push @globalaveragemflatency_1, $averagemflatency_1;
    
    my $averagemflatency_2 = `grep "averagemflatency_2" $file_list[$j] |  tail -n 1 | awk '\{print \$3\}'`;
    chomp($averagemflatency_2);
    push @globalaveragemflatency_2, $averagemflatency_2;
    
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
    
    my $MY_app_2_rank_dist_0 = `grep "^app_2_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$3\}'`;
    chomp($MY_app_2_rank_dist_0);
    push @globalMY_app_2_rank_dist_0, $MY_app_2_rank_dist_0;
    
    my $MY_app_2_rank_dist_1 = `grep "^app_2_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$4\}'`;
    chomp($MY_app_2_rank_dist_1);
    push @globalMY_app_2_rank_dist_1, $MY_app_2_rank_dist_1;
    
    my $MY_app_2_rank_dist_2 = `grep "^app_2_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$5\}'`;
    chomp($MY_app_2_rank_dist_2);
    push @globalMY_app_2_rank_dist_2, $MY_app_2_rank_dist_2;
    
    my $MY_app_2_rank_dist_3 = `grep "^app_2_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$6\}'`;
    chomp($MY_app_2_rank_dist_3);
    push @globalMY_app_2_rank_dist_3, $MY_app_2_rank_dist_3;
    
    my $MY_app_2_rank_dist_4 = `grep "^app_2_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$7\}'`;
    chomp($MY_app_2_rank_dist_4);
    push @globalMY_app_2_rank_dist_4, $MY_app_2_rank_dist_4;
    
    my $MY_app_2_rank_dist_5 = `grep "^app_2_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$8\}'`;
    chomp($MY_app_2_rank_dist_5);
    push @globalMY_app_2_rank_dist_5, $MY_app_2_rank_dist_5;
    
    my $MY_app_2_rank_dist_6 = `grep "^app_2_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$9\}'`;
    chomp($MY_app_2_rank_dist_6);
    push @globalMY_app_2_rank_dist_6, $MY_app_2_rank_dist_6;
    
    my $MY_app_2_rank_dist_7 = `grep "^app_2_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$10\}'`;
    chomp($MY_app_2_rank_dist_7);
    push @globalMY_app_2_rank_dist_7, $MY_app_2_rank_dist_7;
    
    my $MY_app_2_rank_dist_8 = `grep "^app_2_rank_dist" $file_list[$j] | tail -n 1 |  awk '\{print \$11\}'`;
    chomp($MY_app_2_rank_dist_8);
    push @globalMY_app_2_rank_dist_8, $MY_app_2_rank_dist_8;
    
    my $Stream_1_L2missrate = `grep  "Stream 1: L2 Cache Miss Rate" $file_list[$j] | tail -n  1 | awk '\{print \$8\}'`;
    chomp($Stream_1_L2missrate);
    push @globalStream_1_L2missrate, $Stream_1_L2missrate;
    
    my $Stream_2_L2missrate = `grep  "Stream 2: L2 Cache Miss Rate" $file_list[$j] | tail -n  1 | awk '\{print \$8\}'`;
    chomp($Stream_2_L2missrate);
    push @globalStream_2_L2missrate, $Stream_2_L2missrate;
    
    my $L2missrate = `grep  "L2 Cache Total Miss Rate" $file_list[$j] | tail -n  1 | awk '\{print \$7\}'`;
    chomp($L2missrate);
    push @globalL2missrate, $L2missrate;
    
	#}
}

print OUTPUT "Benchmarks \t";
print OUTPUT "AloneIPC1\t";
print OUTPUT "AloneIPC2\t";

print OUTPUT "IPC1\t";
print OUTPUT "IPC2\t";

print OUTPUT "SD1\t";
print OUTPUT "SD2\t";
print OUTPUT "WS\t";
print OUTPUT "IT\t";
print OUTPUT "FI\t";

print OUTPUT "App1-BW \t";
print OUTPUT "App2-BW\t";
print OUTPUT "Waste-BW \t";
print OUTPUT "Idle-BW \t";

print OUTPUT "L2MR-1\t";
print OUTPUT "L2MR-2\t";
print OUTPUT "L2MR\t";

print OUTPUT "Avg-Slack-1\t";
print OUTPUT "Avg-Occupancy-1\t";

print OUTPUT "Avg-Slack-2\t";
print OUTPUT "Avg-Occupancy-2\t";

print OUTPUT "RBL-1 \t";
print OUTPUT "AVGEMF-1 \t";

print OUTPUT "RBL-2 \t";
print OUTPUT "AVGEMF-2 \t";

print OUTPUT "R0-1 \t";
print OUTPUT "R1-1 \t";
print OUTPUT "R2-1 \t";
print OUTPUT "R3-1 \t";
print OUTPUT "R4-1 \t";
print OUTPUT "R5-1 \t";
print OUTPUT "R6-1 \t";
print OUTPUT "R7-1 \t";
print OUTPUT "R8-1 \t";

print OUTPUT "R0-2 \t";
print OUTPUT "R1-2 \t";
print OUTPUT "R2-2 \t";
print OUTPUT "R3-2 \t";
print OUTPUT "R4-2 \t";
print OUTPUT "R5-2 \t";
print OUTPUT "R6-2 \t";
print OUTPUT "R7-2 \t";
print OUTPUT "R8-2 \t";

print OUTPUT "\n";

for ($k = 0;$k <= $#file_list;$k++)
{
	print OUTPUT "$benchmarks[$k] \t";
	print OUTPUT "$sing_ipc1s[$k]\t";
	print OUTPUT "$sing_ipc2s[$k]\t";
	
	#if (-e "$file_list[$k]") {
    print OUTPUT "$ipc_app1[$k] \t";
    print OUTPUT "$ipc_app2[$k] \t";
    
    print OUTPUT "$slowdown1_ar[$k] \t";
    print OUTPUT "$slowdown2_ar[$k] \t";
    print OUTPUT "$speedups[$k]\t";
    print OUTPUT "$throughputs[$k] \t";
    print OUTPUT "$fair_indexes[$k] \t";
    
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
    
    print OUTPUT "$globalrow_locality_1[$k] \t";
    print OUTPUT "$globalaveragemflatency_1[$k] \t";
    
    print OUTPUT "$globalrow_locality_2[$k] \t";
    print OUTPUT "$globalaveragemflatency_2[$k] \t";
    
    print OUTPUT "$globalMY_app_1_rank_dist_0[$k] \t";
    print OUTPUT "$globalMY_app_1_rank_dist_1[$k] \t";
    print OUTPUT "$globalMY_app_1_rank_dist_2[$k] \t";
    print OUTPUT "$globalMY_app_1_rank_dist_3[$k] \t";
    print OUTPUT "$globalMY_app_1_rank_dist_4[$k] \t";
    print OUTPUT "$globalMY_app_1_rank_dist_5[$k] \t";
    print OUTPUT "$globalMY_app_1_rank_dist_6[$k] \t";
    print OUTPUT "$globalMY_app_1_rank_dist_7[$k] \t";
    print OUTPUT "$globalMY_app_1_rank_dist_8[$k] \t";
    
    print OUTPUT "$globalMY_app_2_rank_dist_0[$k] \t";
    print OUTPUT "$globalMY_app_2_rank_dist_1[$k] \t";
    print OUTPUT "$globalMY_app_2_rank_dist_2[$k] \t";
    print OUTPUT "$globalMY_app_2_rank_dist_3[$k] \t";
    print OUTPUT "$globalMY_app_2_rank_dist_4[$k] \t";
    print OUTPUT "$globalMY_app_2_rank_dist_5[$k] \t";
    print OUTPUT "$globalMY_app_2_rank_dist_6[$k] \t";
    print OUTPUT "$globalMY_app_2_rank_dist_7[$k] \t";
    print OUTPUT "$globalMY_app_2_rank_dist_8[$k] \t";
	#}
    
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
