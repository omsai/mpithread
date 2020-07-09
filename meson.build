project('mpithread', ['c', 'fortran'], version : '0.1')


libmpi = dependency('mpich', required : false)
if not libmpi.found()
  libmpi = dependency('mpi')
endif
executable('thread_level',
	   'thread_level.c',
	   dependencies : libmpi)
executable('ping_pong',
	   'ping_pong.c',
	   dependencies : libmpi)
executable('hostnames',
	   'hostnames.c',
	   dependencies : libmpi)
