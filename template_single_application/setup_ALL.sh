#!/bin/sh
sh setup_CUDA.sh $1
sh setup_rodinia.sh $1
sh setup_parboil.sh $1
sh setup_mars.sh $1
sh setup_shoc.sh $1
sh setup_cache_sense.sh $1
sh setup_lonestar.sh $1
sh setup_nvkernels.sh $1
