#include <iostream>
#include <time.h>
#include <cstdlib>
#include "mpi.h"
#define n 1000

void my_max(void *a, void *b, int *l, MPI_Datatype *type)
{
	for (int i = 0; i < *l; i++)
	    ((int*)b)[i] = std::max(((int*)a)[i], ((int*)b)[i]);
}

int main(int argc, char **argv)
{
	int rank, size, i;
	int a[n];
	int b[n], test[n];
	MPI_Init(&argc, &argv);
	MPI_Op op;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	for (i = 0; i < n; i++) a[i] = i + rank + 1;
	printf("process %d a[0] = %d\n", rank, a[0]);
	MPI_Op_create(&my_max, 1, &op);
	MPI_Reduce(a, b, n, MPI_INT, op , 0, MPI_COMM_WORLD);
	MPI_Op_free(&op);
	MPI_Reduce(a, test, n, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
	if (rank == 0) printf("Own result = %d; MPI_MAX result = %d\n", b[0], test[0]);
	MPI_Finalize();
}