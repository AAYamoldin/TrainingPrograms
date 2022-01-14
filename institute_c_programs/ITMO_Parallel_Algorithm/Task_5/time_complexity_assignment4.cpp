#include <stdio.h>
#include <iostream>
#include "mpi.h"
using namespace std;
int main(int argc, char* argv[]) {
    double time_start, time_finish;
	MPI_Init(&argc, &argv);
	int rank, n, i, message, previos_number, is_descending;
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD, &n);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    time_start = MPI_Wtime();
	if (rank == 0)
	{
		cout << "Hello from process " << rank << "\n";
		previos_number = rank;
		is_descending = 1;
		for (i = 1; i < n; i++) {
			MPI_Recv(&message, 1, MPI_INT, MPI_ANY_SOURCE,
			         MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			if (is_descending)
			{
				if (previos_number < message)
				{
					is_descending = 0;
				}
			}
			cout << "Hello from process " << message << endl;  
		}
		is_descending ? cout << "Sequence is descending" << endl : cout << "Sequence in not descending" << endl;
	}
	else MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    time_finish = MPI_Wtime();
    cout << "process " << rank << " time = " << (time_finish - time_start) << endl;
	MPI_Finalize();
	return 0;
}

