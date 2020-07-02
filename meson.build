project('mpithread', 'c', version : '0.1')
libmpi = dependency('mpich')
executable('thread_level',
	   'thread_level.c',
	   dependencies : libmpi)
executable('ping_pong',
	   'ping_pong.c',
	   dependencies : libmpi)
