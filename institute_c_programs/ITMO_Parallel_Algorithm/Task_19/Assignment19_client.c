#include <stdio.h> 
#include <string.h> 
#include "mpi.h" 
#include <iostream>


using namespace std;

int main(int argc, char **argv) { 

	int rank; 
	int msg = 6; 
	MPI_Init(&argc, &argv); 
	char port_name[MPI_MAX_PORT_NAME]; 
	MPI_Comm intercomm; 
	MPI_Status status; 
	strcpy(port_name, argv[1]); 

	MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

	MPI_Send(&msg, 1, MPI_INT, 0, 1, intercomm); 
	cout << "Клиент отправил: " + to_string(msg) + "\n"; 

	MPI_Recv(&rank, 1, MPI_INT, 0, 2, intercomm, &status); 
	cout << "Клиент получил: " + to_string(rank) + "\n";

	MPI_Finalize(); 

return 0; 

} 