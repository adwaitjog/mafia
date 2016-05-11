MAFIA: Multiple Application Framework for GPU Architectures
-----------------------------------------------------------

MAFIA is developed for supporting multiple applications execution on GPUs. This
framework is implemented by extending v3.2 GPGPU-Sim simulator from UBC. Currently, 
it supports 25 benchmarks from various benchmark suites (e.g., CUDA, Parboil, SHOC and Rodinia). 
From these benchmarks, one can construct 300 2-application workloads and 2300 3-application 
workloads. 

If you use or build on this framework, please cite:

Adwait Jog, Onur Kayiran, Tuba Kesten, Ashutosh Pattnaik, Evgeny Bolotin, Niladrish Chatterjee, Stephen W. Keckler, 
Mahmut T. Kandemir, Chita R. Das, Anatomy of GPU Memory System for Multi-Application Execution, 
In the Proceedings of 1st International Symposium on Memory Systems (MEMSYS), Washington, DC, Oct 2015 

Basics of MAFIA
-----------------------------------------------------------

You need to first setup GPGPU-Sim before starting to play MAFIA :-). GPGPU-Sim can be found at
http://www.gpgpu-sim.org/. Please use CUDA 4.0 and GCC version less than 4.5 (we used 4.4.6).

How to set-up MAFIA?
-----------------------------------------------------------

1. Pull the repo to your favorite folder

2. Change "GCC_VERSION ?=" to the one of yours in common/common_pthread.mk

3. Do a "make" in the GPGPU-Sim repo after setting appropriate enviornment variables.

4. Execute ./compile.sh in the pthread_benchmark folder. 

5. If all above commands are successful, the framework is ready to use. 

How to play MAFIA?
-----------------------------------------------------------

1. You can see the available benchmarks in MAFIABENCHMARKS file.

2. Make sure you have the following three files located in your benchmark folder.
 
	gpgpusim.config , gpuwattch_gtx480.xml, config_fermi_islip.icnt

3. Our framework has 4 modes:

	Single application with entire system : Executes single application by using entire SMs

	Single application: Executes single application based on number of allocated SMs

	2-application : Executes 2 application together

	3-application : Executes 3 application together

4. To run framework with one these modes, modify/add gpgpusim.config.

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
	
If you modify the number of SMs, make sure you configure the interconnection network parameters accordingly in ‘config_fermi_islip.icnt’

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


Where to find MAFIA results?
-----------------------------------------------------------

Our framework generates 3 output file (Stream1.txt, Stream2.txt and Stream3.txt) which represents the maximum number of benchmarks can be executed. Output files can be matched based on the argument order. For instance,

./gpgpu_ptx_sim__mergedapps -apps BLK SCP

Stream1.txt -> Output for BLK
Stream2.txt -> Output for SCP
Stream3.txt -> Empty

Note: In single application mode, you should use the console output of MAFIA. You can re-direct the console output to a file. 
















