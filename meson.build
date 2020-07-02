project('mpithread', 'c', version : '0.1')
libmpi = dependency('mpich')
executable('print_thread_level',
	   'print_thread_level.c',
	   dependencies : libmpi)
executable('ping_pong',
	   'ping_pong.c',
	   dependencies : libmpi)
