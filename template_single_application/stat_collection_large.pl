#!/usr/bin/perl -w 

use English;

@benchmarks = (
"lulesh", "BFS2", "KMNS",
"ST2D", "TRD", "RED", "Scan", 
"MUM", "FWT", "SCP", "CONS", "NN", "JPEG", "SLA", "STO", "NN", "LIB", "LPS", "AES", "BlackScholes",
"bfs-l", "bh-l", "mst-l", "sp-l", "sssp-l", "dmr-l", 
"backprop", "hotspot","heartwall", "streamcluster", "lud", "nw", "cfd",
"mm", "spmv", "histo", "sad",
"PVC", "PVR", "SSC",
"gauss");

@file_list = (
"cache_sense/lulesh/output_lulesh.txt", 
"cache_sense/BFS2S/output_BFS2S.txt", 
"cache_sense/KMNS/output_KMNS.txt", 
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
"CUDA/SLA/output_SLA.txt",
"CUDA/STO/output_STO.txt",
"CUDA/NN/output_NN.txt",
"CUDA/LIB/output_LIB.txt",
"CUDA/LPS/output_LPS.txt",
"CUDA/AES/output_AES.txt",
"CUDA/BlackScholes/output_BlackScholes.txt",
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
"parboil/histo/output_histo.txt",
"parboil/sad/output_sad.txt",
"Mars/PageViewCount/output_PVC.txt", 
"Mars/PageViewRank/output_PVR.txt", 
"Mars/SimilarityScore/output_SSC.txt", 
"nvkernels/gauss/output_gauss.txt"
);
#"nvkernels/gups/output_gups.txt",
#"nvkernels/dgemm/output_dgemm.txt",

$result_file = "all_results_large.txt";

open(OUTPUT, ">$result_file") || die "Cannot open file $result_file for writing\n";

for ($j = 0; $j <= $#file_list; $j++)
{
                my $ipc = `grep gpu_tot_ipc $file_list[$j] | tail -n 1 | awk '\{print \$3\}'`;
                chomp($ipc);
                push @globalipc, $ipc;
}
	print OUTPUT "Benchmarks \t";
	print OUTPUT "IPC\t";
	print OUTPUT "\n";
	
for ($k = 0;$k <= $#file_list;$k++) 
{
	print OUTPUT "$benchmarks[$k] \t";
	print OUTPUT "$globalipc[$k] \t";
	print OUTPUT "\n";
}
