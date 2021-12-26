#include <stdio.h>
#include "mpi.h"
#include <iostream>


using namespace std;
int main(int argc, char **argv)
{
	int r;
	MPI_Init(&argc, &argv);
	char port_name[MPI_MAX_PORT_NAME];
	MPI_Status status;
	MPI_Comm intercomm;
	MPI_Open_port(MPI_INFO_NULL, port_name);
	cout << "Portname :" << port_name;
	MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
	cout << "Connection succesful\n";
	int msg = 16;
	MPI_Send(&msg, 4, MPI_CHAR, 0, 2, intercomm);
	cout << "Сервер отправил: " <<  msg << endl;
	int rec_msg;
	MPI_Recv(&rec_msg, 5, MPI_CHAR, 0, 1, intercomm, &status);
	cout << "Сервер получил: " + to_string(rec_msg) << endl;
	MPI_Comm_free(&intercomm);
	MPI_Close_port(port_name);

	MPI_Finalize();
	return 0;
}