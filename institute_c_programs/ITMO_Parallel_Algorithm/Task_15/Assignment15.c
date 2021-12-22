#include "mpi.h"
#include <iostream>
int main(int argc, char **argv)
{
	int rank, size, i, rbuf;
	MPI_Init(&argc, &argv);
	MPI_Group group, new_group;
	MPI_Comm new_comm;
	int ranks[128], new_rank;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_group(MPI_COMM_WORLD, &group);/*Конструкторы групп применяются к подмножеству и расширенному множеству
	 существующих групп. Эти конструкторы создают новые группы на основе существующих групп. 
	 Данные операции являются локальными и различные группы могут быть определены на различных процессах; 
	 процесс может также определять группу, которая не включает саму себя. 
	 MPI не имеет механизма для формирования группы с нуля, группа может формироваться только на основе другой, 
	 предварительно определенной группы. 
	 Базовая группа, на основе которой определены все другие группы, является группой, 
	 связанной с начальным коммуникатором MPI_COMM_WORLD (доступна через функцию MPI_COMM_GROUP).*/

	for (i = 0; i < size / 2; i++) ranks[i] = i;

	if (rank < size / 2) MPI_Group_incl(group, size / 2, ranks, &new_group);/*Функция MPI_GROUP_INCL создает группу 
	newgroup, которая состоит из n процессов из group с номерами ranks[0],..., ranks[n-1]; 
	процесс с номером i в newgroup есть процесс с номером ranks[i] в group. 
	Каждый из n элементов ranks должен быть правильным номером в group, и все элементы должны быть различными,
	иначе программа будет неверна. Если n = 0, то newgroup имеет значение MPI_GROUP_EMPTY.*/
	else MPI_Group_excl(group, size / 2, ranks, &new_group);
	
	MPI_Comm_create(MPI_COMM_WORLD, new_group, &new_comm);
	MPI_Allreduce(&rank, &rbuf, 1, MPI_INT, MPI_SUM, new_comm);
	MPI_Group_rank(new_group, &new_rank);
	
	std::cout << "rank = " << rank <<  " newrank = " << new_rank <<  " rbuf = " << rbuf << std::endl;
	
	MPI_Finalize();
}