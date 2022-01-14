#include <cstdlib>
#include "mpi.h"
int main(int argc, char **argv)
{
	int rank, comm_size;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//matrix initialization by each process
	int size = 500;
	int A[size][size], B[size][size], C[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0;
        }
    double start, end;

	MPI_Barrier(MPI_COMM_WORLD); //barrier process synchronization
// start timing for each process
	start = MPI_Wtime();
// matrix multiplication
	for (int i = 0; i < size; i++)
	{
	    for (int j = 0; j < size; j++)
	    {
	        for (int k = 0; k < size; k++)
	        {
	            C[i][j] += A[i][k] * B[k][j];
	        }
	    }
	}
// end of timing
	end = MPI_Wtime();
// output the execution time of matrix multiplication at each process
	printf("Process %d: time elapsed %.0f ms\n", rank, (end - start) * 1000);

	MPI_Finalize();
}