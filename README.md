# MPI and threading examples

Minimal examples written in C to test the MPI runtime environment.

# Installation

Compiling the examples uses the `meson` build system available from
the python package repository.

    python3 -m pip install --user --upgrade meson ninja
    PATH=$HOME/.local/bin:$PATH

# Compiling

One of the many advantages of `meson` is it will remember all
dependency paths and automatically compile in all `rpath` directories
into the targets, so after configuring the build with the `meson`
command, you never have to worry about loading any modules!

	# MPICH
    module purge ; module load mpi/mpich/3.3.1
	meson build-mpich
	module purge
	ninja -v -C build-mpich

	# OpenMPI
	module purge ; module load gcc/5.4.0-alt zlib/1.2.11 java/1.8.0_162 mpi/openmpi/3.1.3
	meson build-openmpi
	module purge
	ninja -v -C build-openmpi

# Running

A convenience wrapper is provided in `test-slurm.bash` for running all
the MPI programs.

	cd build-mpich
	meson test -v
	cd ..

	cd build-openmpi
	meson test -v
	cd ..
