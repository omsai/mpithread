/* https://www.openmp.org/wp-content/uploads/OpenMP-4.0-C.pdf 
   https://www.openmp.org/wp-content/uploads/OpenMP4.0.0.pdf*/
#include "mpi.h"
#include "omp.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int ntasks, rank, len, nthreads, thread;
  char processor_name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &len);
  #pragma omp parallel
  {
    nthreads = omp_get_num_threads();
    thread = omp_get_thread_num();
    printf("%d.%d: ntasks : %d, processor_name[%d] : %s, nthreads : %d\n",
	   rank, thread, ntasks, len, processor_name, nthreads);
  }

  MPI_Finalize();

  return 0;
}
