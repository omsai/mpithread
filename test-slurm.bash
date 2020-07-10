#!/bin/bash -x
set -e
module purge
source config.bash
$srun $PWD/thread_level
$srun -n 3 $PWD/ping_pong
$srun -n 3 $PWD/hostnames
$srun -n 2 -c 3 $PWD/openmp
