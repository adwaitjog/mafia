MAFIA (Multiple Application Framework in GPU Architectures)
-----------------------------------------------------------
MAFIA was developed for supporting multiple applications execution on GPUs by HPCL Group
at The Pennsylvania State University. Currently, it supports 25 benchmarks from various 
benchmark suites(CUDA, Parboil, SHOC and Rodinia).From these benchmarks, you can construct 
300 2-application workloads and 2300 3-application workloads.It was implemented by extending 
v3.2 GPGPU-Sim simulator.


Setting up Environment 
----------------------
To enable working with MAFIA, first you need to setup GPGPU-Sim. The simulator can be found at
http://www.gpgpu-sim.org/

After downloading GPGPU-Sim, make sure you installed all dependencies required. You can take a look into GPGPU-Sim README file for the detailed information.

==Modify GPGPU-Sim For MAFIA Framework==

1. Please use CUDA 4.0, and GCC version less than 4.5 (We used 4.4.6)
2. Please pull the latest GPGPU-SIM repo and then replace its corresponding files and folders with 
the one in the MAFIA repo. There are some additional folders and files in MAFIA repo. Also, add them to the GPGPUSIM repo.
3. Change "GCC_VERSION ?=" to the one of yours in common/common_pthread.mk
4. Do a "make" in the GPGPU-Sim repo after setting appropriate enviornment variables.
5. Do a "make" in the pthread_benchmark folder. 
6. If all above commands are successful, the framework is ready to use. 

==Running benchmarks on MAFIA Framework==

1. You can see the available benchmarks in MAFIABENCHMARKS file.

2. Make sure, you have the following three files located in your benchmark folder.
	gpgpusim.config , gpuwattch_gtx480.xml, config_fermi_islip.icnt

3. Our framework has 4 modes:
	Single application with entire system : Executes single application by using entire SMs
	Single application: Executes single application based on number of allocated SMs
	2-application : Executes 2 application together
	3-application : Executes 3 application together

4. To run framework with one these modes, modify some parameters in gpgpusim.config.
	
	-gpgpu_n_clusters : indicates the number of SMs in the system.For 3-application mode, make sure that you choose a SMs number divisible by 3.
	-gpgpu_sms_app1 : indicates the number of SMs assigned to first application.
	-gpgpu_mode3 : indicates whether 3-application mode enabled or not.
	-gpu_app : indicates whether 2-application mode enabled or not.

Examples:
2 application execution with even SM partitioning (15-15)
-gpgpu_n_clusters 30
-gpgpu_sms_app1 15
-gpgpu_mode3 0
-gpu_app 1

2 application execution (12-24)
-gpgpu_n_clusters 36
-gpgpu_sms_app1 12
-gpgpu_mode3 0
-gpu_app 1
	
3 application execution(10-10-10)
-gpgpu_n_clusters 30
-gpgpu_sms_app1 15
-gpgpu_mode3 1
-gpu_app 1

single application execution (10)
-gpgpu_n_clusters 30
-gpgpu_sms_app1 10
-gpgpu_mode3 0
-gpu_app 0

If you modify the number of SMs, make sure you configure the interconnection network parameters in ‘config_fermi_islip.icnt’

5. After compilation, the executable file called ‘gpgpu_ptx_sim__mergedapps’ will be generated. To run, the following command will work:
	./gpgpu_ptx_sim__mergedapps <mode_name> <appnames>

<mode_name>

	Single application with entire system : -sing0
	Single application: -sing
	2-application : -apps
	3-application : -apps3
<appnames>
You can find abbreviations for benchmarks in MAFIABENCHMARKS file.

Examples:

Here some examples how to run benchmarks from our framework. BLK stands for Blackscholes benchmark, SCP stands for Scalar product benchmark and HISTO stands for Histogram benchmark. 

Single application
./gpgpu_ptx_sim__mergedapps -sing BLK

Single application with entire system 
./gpgpu_ptx_sim__mergedapps -sing0 BLK

2-application
./gpgpu_ptx_sim__mergedapps -apps BLK SCP

3-application
./gpgpu_ptx_sim__mergedapps -apps3 BLK SCP HISTO

==Results==
Our framework generates 3 output file (Stream1.txt, Stream2.txt and Stream3.txt) which represents the maximum number of benchmarks can be executed. Output files can be matched based on the argument order. For instance,

./gpgpu_ptx_sim__mergedapps -apps BLK SCP

Stream1.txt -> Output for BLK
Stream2.txt -> Output for SCP
Stream3.txt -> Empty
















