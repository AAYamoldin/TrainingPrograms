#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define NELMS 1000000
#define MASTER 0
#define MAXPROCS 12

int dot_product(int s,int e, int x[], int y[], int n){
  int i,prod=0;

  for (i = s; i < e; i++)
    prod = prod + x[i] * y[i];
  
  return prod;
}

void init_lst(int *l,int n){
  int i;
  for (i=0; i<n; i++) *l++ = i;
}
void print_lst(int s,int e, int *l){
  int i;
  for (i=s; i<e; i++) {
    printf("%x ",l[i]);
  }
  printf("\n");
}


int main(int argc, char **argv) {
  int i,n,vector_x[NELMS],vector_y[NELMS];
  int prod,sidx,eidx,size;
  int pid,nprocs, rank;
  double stime,etime;
  MPI_Status status;
  MPI_Comm world;

  n = atoi(argv[1]);
  if (n > NELMS) { printf("n=%d > N=%d\n",n,NELMS); exit(1); }
  int portion = n / nprocs;//деление с округлением в меньшую сторону
  MPI_Init(&argc, &argv);
  world = MPI_COMM_WORLD;
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  sidx = pid * portion;//с какого элемента обрабатывает каждый поток
  eidx = sidx + portion;//до какого элемента обрабатывает каждый поток
  init_lst(vector_x, n);
  init_lst(vector_y, n);
  
  int tmp_prod[nprocs];
  for (i = 0; i < nprocs; i++)
    tmp_prod[i] = 0;

  stime = MPI_Wtime();

  if (pid == MASTER) {
    prod = dot_product(sidx, eidx, vector_x, vector_y, n);
    for (i = 1; i < nprocs; i++)
      MPI_Recv(&tmp_prod[i-1], 1, MPI_INT, i, 123, MPI_COMM_WORLD, &status);//прием результатов от всех других потоков
  }
  else {
    prod = dot_product(sidx, eidx, vector_x, vector_y, n);//подсчет произведений на всех других потоках
    MPI_Send(&prod, 1, MPI_INT, MASTER, 123, MPI_COMM_WORLD);//отправка результата в мастер поток (в нулевой)
  }

  if (pid == MASTER) {
    for (i = 0; i < nprocs; i++)
      prod += tmp_prod[i];//сборка результата в мастер потоке
  }
  
  etime = MPI_Wtime();

  if (pid == MASTER) {
    printf("The result of dot multiplication =%d\n",prod);
    printf(" elapsed=%f\n",etime-stime);
  }
  MPI_Finalize();
}
