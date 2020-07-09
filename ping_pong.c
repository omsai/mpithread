/* From https://computing.llnl.gov/tutorials/mpi/ */
#include "mpi.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void str(MPI_Status stat, char* str_stat) {
  sprintf(str_stat,
	  "{ "
	  "SOURCE : %d, "
	  "TAG : %d, "
	  "ERROR : %d "
	  "}",
	  stat.MPI_SOURCE,
	  stat.MPI_TAG,
	  stat.MPI_ERROR);
}

int main (int argc, char *argv[]) {
  int ntasks, rank, dst, src, rc, tag = 1;
  char imsg, omsg = 'x';
  MPI_Status stat;
  char str_stat[255];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
  if (ntasks < 2) {
    printf("Error: Need at least 2 MPI tasks but found %d!\n", ntasks);
    return 1;
  }
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0) {
    dst = 1;
    src = 1;

    omsg += 1;
    printf("%d: '%c' ->  %d\n", rank, omsg, dst);
    rc = MPI_Send(&omsg, 1, MPI_CHAR, dst, tag, MPI_COMM_WORLD);
    assert(rc == 0);

    printf("%d: Waiting for %d\n", rank, src);
    rc = MPI_Recv(&imsg, 1, MPI_CHAR, src, tag, MPI_COMM_WORLD, &stat);
    assert(rc == 0);
    str(stat, str_stat);
    printf("%d:  %d  -> '%c' status : %s\n", rank, src, imsg, str_stat);
  } else if (rank == 1) {
    dst = 0;
    src = 0;

    printf("%d: Waiting for %d\n", rank, src);
    rc = MPI_Recv(&imsg, 1, MPI_CHAR, src, tag, MPI_COMM_WORLD, &stat);
    assert(rc == 0);
    str(stat, str_stat);
    printf("%d:  %d  -> '%c' status: %s\n", rank, src, imsg, str_stat);

    omsg += 2;
    printf("%d: '%c' ->  %d\n", rank, omsg, src);
    rc = MPI_Send(&omsg, 1, MPI_CHAR, dst, tag, MPI_COMM_WORLD);
    assert(rc == 0);
  } else {
    printf("%d: Nothing to do!\n", rank);
  }

  MPI_Finalize();

  return 0;
}
