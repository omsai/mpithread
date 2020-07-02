/* From https://computing.llnl.gov/tutorials/mpi/ */
#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int ntasks, rank, len; 
  char processor_name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &len);
  printf("%d: ntasks : %d, processor_name[%d] : %s\n",
	 rank, ntasks, len, processor_name);

  MPI_Finalize();

  return 0;
}
