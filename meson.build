project('mpithread', ['c', 'fortran'], version : '0.1')

conf = configuration_data()
libmpi = dependency('mpich', required : false)
if not libmpi.found()
  libmpi = dependency('mpi')
  conf.set('srun_mpi', 'openmpi')
else
  conf.set('srun_mpi', 'pmi2')
endif
libopenmp = dependency('openmp')
configure_file(input : 'config.bash.in',
	       output : 'config.bash',
	       configuration : conf)

executable('thread_level',
	   'thread_level.c',
	   dependencies : libmpi)
executable('ping_pong',
	   'ping_pong.c',
	   dependencies : libmpi)
executable('hostnames',
	   'hostnames.c',
	   dependencies : libmpi)
executable('openmp',
	   'openmp.c',
	   dependencies : [libmpi, libopenmp])

test_runner = find_program('test-slurm.bash')
test('Run all tests', test_runner)
