#include <iostream>
#include <mpi.h>
using namespace std;
int main(int argc, char **argv)
{
	int rank, size, ibuf;
	MPI_Status status;
	float rbuf;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ibuf = rank;
	rbuf = 1.0 * rank;
	if (rank == 1) MPI_Send(&ibuf, 1, MPI_INT, 0, 5, MPI_COMM_WORLD);/* на 1 процессе передача ibuf в 0 процесс с тэгом 5*/
	if (rank == 2) MPI_Send(&rbuf, 1, MPI_FLOAT, 0, 6, MPI_COMM_WORLD);/*на 2 процессе передача rbuf в 0 процесс с тэгом 5*/
	if (rank == 0) {/* в нулевом процессе*/
		MPI_Probe(MPI_ANY_SOURCE, 6, MPI_COMM_WORLD, &status);/*Выделям память для хранения принимаемого сообщения
		на входе: от какого процесса получаем память
		с тегом 5
		какой коммуникатор связывает эти процессы
		и структура записи необходимой информации*/
		if (status.MPI_TAG == 5) {/*если источник принимаемого сообщения = 1(1 процесс)*/
			MPI_Recv(&ibuf, 1, MPI_INT, 1, 5, MPI_COMM_WORLD, &status);//прием сообщений 
			MPI_Recv(&rbuf, 1, MPI_FLOAT, 2, 6, MPI_COMM_WORLD, &status);//прием сообщений
			cout << "Process 0 recv " << ibuf << " from process 1, " << rbuf << " from process 2\n";
		}
		else if (status.MPI_TAG == 6) {
			MPI_Recv(&rbuf, 1, MPI_FLOAT, 2, 6, MPI_COMM_WORLD, &status);
			MPI_Recv(&ibuf, 1, MPI_INT, 1, 5, MPI_COMM_WORLD, &status);
			cout << "Process 0 recv " << rbuf << " from process 2, " << ibuf << " from process 1\n";
		}
	}
	MPI_Finalize();
}