#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

// функция генерации случайного числа из диапазона от range_min до range_max включительно
int rrand(int range_min, int range_max) {
  return rand() % (range_max - range_min + 1) + range_min;
}

const unsigned int ARRSIZE = 8500;
const int ABSLIMIT = 9;

int A[ARRSIZE][ARRSIZE];
int B[ARRSIZE][ARRSIZE];
int A5[ARRSIZE][ARRSIZE];
int B8[ARRSIZE][ARRSIZE];
int AB[ARRSIZE][ARRSIZE];
int A5mB8[ARRSIZE][ARRSIZE];
int RESULT[ARRSIZE][ARRSIZE];

void  print_matrix(int A[][ARRSIZE])
{
  int i = 0;
  int j = 0;
  while (i < ARRSIZE)
  {
    while (j < ARRSIZE)
    {
      //   printf("%-5d ", A[i][j]);
      j++;
    }
    j = 0;
    i++;
    // printf("\n");
  }
}

int main(void)
{
  // заполнили две матрицы A, B рандомными числами
  int i = 0;
  int j = 0;
  int nthreads;
  clock_t clock_timer;
  double wall_timer;

  while (i < ARRSIZE)
  {
    while (j < ARRSIZE)
    {
      A[i][j] = rrand(-ABSLIMIT, ABSLIMIT);
      B[i][j] = rrand(-ABSLIMIT, ABSLIMIT);
      j++;
    }
    j = 0;
    i++;
  }
  //  printf("This is matrix A\n");
  // print_matrix(A);
  // printf("This is matrix B\n");
  // print_matrix(B);
  // запускаем в расспараллеливание операцию А*5
  for (nthreads = 1; nthreads <=4; ++nthreads) {
    clock_timer = clock();
    wall_timer = omp_get_wtime();
    #pragma omp parallel for num_threads(nthreads)
    for (i = 0; i < ARRSIZE; i++)
    {
      for (j = 0; j < ARRSIZE; j++)
      {
        A5[i][j] = A[i][j] * 5;
      }
    }
    // запускаем в расспараллеливание операцию В*8
    #pragma omp parallel for num_threads(nthreads)
    for (i = 0; i < ARRSIZE; i++)
    {
      for (j = 0; j < ARRSIZE; j++)
      {
        B8[i][j] = B[i][j] * 8;
      }
    }
    // запускаем в расспараллеливание операцию A x B
    #pragma omp parallel for num_threads(nthreads)
    for (i = 0; i < ARRSIZE; i++)
    {
      for (j = 0; j < ARRSIZE; j++)
      {
        AB[i][j] = A[i][j] * B[j][i];
      }
    }
    // запускаем в расспараллеливание операцию A5 - B8
    #pragma omp parallel for num_threads(nthreads)
    for (i = 0; i < ARRSIZE; i++)
    {
      for (j = 0; j < ARRSIZE; j++)
      {
        A5mB8[i][j] = A5[i][j] - B8[i][j];
      }
    }
    // запускаем в расспараллеливание операцию (A5 - B8) * A x B
    #pragma omp parallel for num_threads(nthreads)
    for (i = 0; i < ARRSIZE; i++)
    {
      for (j = 0; j < ARRSIZE; j++)
      {
        RESULT[i][j] = A5mB8[i][j] + AB[i][j];
      }
    }
    std::cout << "threads: " << nthreads <<  " time on clock(): " <<
    (double) (clock() - clock_timer) / CLOCKS_PER_SEC
    << " time on wall: " <<  omp_get_wtime() - wall_timer << "\n";
  }
  // printf("Result of calculates is\n");
  //  print_matrix(RESULT);

  return 0;
}
