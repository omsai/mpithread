/* From https://computing.llnl.gov/tutorials/mpi/ */
#include "mpi.h"
#include <stdio.h>

int main() {
    int provided, claimed;

    printf("Enumeration for MPI_THREAD_*:\n"
	   "MPI_THREAD_SINGLE: %d\n"
	   "MPI_THREAD_FUNNELED: %d\n"
	   "MPI_THREAD_SERIALIZED: %d\n"
	   "MPI_THREAD_MULTIPLE: %d\n\n",
	   MPI_THREAD_SINGLE,
	   MPI_THREAD_FUNNELED,
	   MPI_THREAD_SERIALIZED,
	   MPI_THREAD_MULTIPLE);

    MPI_Init_thread(0, 0, MPI_THREAD_MULTIPLE, &provided);
    MPI_Query_thread(&claimed);
        printf("Query thread level = %d\n Init_thread level = %d\n",
		claimed, provided);

    MPI_Finalize();
}
