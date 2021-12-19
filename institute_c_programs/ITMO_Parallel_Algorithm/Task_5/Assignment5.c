#include <iostream>
#include "mpi.h"
#define NTIMES 100
using namespace std;
int main(int argc, char **argv)
{
	double time_start, time_finish;
	int rank, i;
	int len;
	char *name = new char;
	MPI_Init(&argc, &argv);//Процедура инициализации параллельной части
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);/*Процедура, позволяющая узнать на каком из процессов работает
	конкретный экземпляр программы.на вход глобальный коммуникатор и номер конкретного процесса*/
	MPI_Get_processor_name(name, &len);/*Процедура, позволяющая узнать имя физического процессора на котором
	выполняется программа
	На входе: ссылка на область памяти, куда нужно записать имя физического процессора
	ссылку куда будет записана длина этой строки*/
	time_start = MPI_Wtime();/*Процедура, возвращающая астрономическое время в секундах на 
	вызывавшем её процессе*/
	for (i = 0; i < NTIMES; i++)
		time_finish = MPI_Wtime();
	cout << "processor " << name << ", process " << rank << " time = " << (time_finish - time_start) / NTIMES << endl;
	MPI_Finalize();
}