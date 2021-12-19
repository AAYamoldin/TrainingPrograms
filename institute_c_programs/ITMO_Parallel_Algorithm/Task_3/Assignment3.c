#include <iostream>
#include "mpi.h"
using namespace std;
int main(int argc, char* argv[]) {
	MPI_Init(&argc, &argv);//Процедура инициализации параллельной части
	int rank, n, i, message;
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD, &n);//Процедура позволяющая узнать на каком потоке запущена программа
	//Принимает на вход глобальный коммуникатор и количество потоков, обрабатывающих программу
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);//Процедура, позволяющая узнать на каком из процессов работает
	//конкретный экземпляр программы.на вход глобальный коммуникатор и номер конкретного процесса
	if (rank == 0)//Выполняется для нулевого потока
	{
		cout << "Hello from process " << rank << "\n";//всегда будет 0 процесс выводиться первым
		for (i  = 1; i < n; i++) {
			MPI_Recv(&message, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);/*
			Процедура приёма сообщений, осуществляющая блокирущий приём данных
			На входе: ссылка на адрес, по которому будут сохранены передаваемые данные
			максимальное количество принимаемых элементов
			тип данных
			номер процесса, который отправил сообщение
			id сообщения, которое мы принимаем
			Коммуникатор в котором находится процесс ОТ которого получаем сообщение
			структура, определенная в mpi которая хранит информацию о пересылке и статусе её завершения*/
			cout << "Hello from process " << message << endl;/*в распараллеленном режиме печатаем
			пришедшее сообщение*/
		}
	}
	else MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);/*процедура передачи сообщений с блокировкой
	на входе: ссылка на данные, которые мы пересылаем(в случае массива ссылка на 1 элемент),
	колчество элементов в этом массиве
	тип данных
	номер процесса, которому отправляем сообщение
	id- сообщения
	коммуникатор в котором находится процесс, которому отправляем сообщение*/
	MPI_Finalize();//Процедура завершения параллельной части программы
	return 0;
}

/* Console out
root@DESKTOP-6HRJV3D:~/TrainingPrograms/institute_c_programs/ITMO_Parallel_Algorithm/Task_3# mpiexec -n 10 ./A3
Hello from process 0
Hello from process 1
Hello from process 2
Hello from process 3
Hello from process 4
Hello from process 5
Hello from process 6
Hello from process 7
Hello from process 8
Hello from process 9
*/