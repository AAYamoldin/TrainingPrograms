#include <stdio.h>
#include "mpi.h"
#include <iostream>
#include <cstring>
#define BUFSIZE 29

using namespace std;
int main(int argc, char **argv)
{
	int bufsize, num, sum;
	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_File fh;
	char buf[BUFSIZE];
	MPI_File_open(MPI_COMM_WORLD, "file.txt", MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &fh);
	MPI_File_write(fh, "Testing file write function\0", 28, MPI_CHAR, &status);
	MPI_File_close(&fh);


	MPI_File_open(MPI_COMM_WORLD, "file.txt", MPI_MODE_RDONLY, MPI_INFO_NULL, &fh);
	MPI_File_set_view(fh, 0, MPI_CHAR, MPI_CHAR, "native", MPI_INFO_NULL);
	sum = 0;
	do {
		MPI_File_read(fh, buf, BUFSIZE, MPI_CHAR, &status);
		MPI_Get_count(&status, MPI_CHAR, &num);
		printf("buf=%s\n", buf);
		sum += num;
	} while (num >= BUFSIZE);
	MPI_File_close(&fh);

	cout << "Symbols count : " + to_string(sum) + ";\n";

	if (argc > 1 && strcmp(argv[1], "--delete") == 0){
		MPI_File_delete("file.txt", MPI_INFO_NULL);
		cout << "File deleted.\n";
	}
	else {
		cout << "File crated.\n";
	}
	MPI_Finalize();
}