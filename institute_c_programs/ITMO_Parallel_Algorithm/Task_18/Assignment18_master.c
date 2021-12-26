#include "mpi.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
	int size, rank1, rank2, number_of_processes;
	MPI_Status status;
	MPI_Comm intercomm;
	char slave[20] = "./A18_s";
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_spawn(slave, MPI_ARGV_NULL, 3, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm, MPI_ERRCODES_IGNORE);
	MPI_Recv(&rank1, 1, MPI_INT, 0, 0, intercomm, &status);
	MPI_Recv(&rank2, 1, MPI_INT, 1, 1, intercomm, &status);

	cout << "Slave 1 rank : " + to_string(rank1) + ";\nSlave 2 rank : " + to_string(rank2) + ";\n";

	MPI_Recv(&number_of_processes, 1, MPI_INT, 2, 2, intercomm, &status);
	cout << "Slave " + to_string(status.MPI_SOURCE) + "send message, number of processes = " + to_string(number_of_processes) << "\n"; 

	MPI_Finalize();
	return 0;
}