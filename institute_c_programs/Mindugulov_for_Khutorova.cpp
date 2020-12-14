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

const long long int ARRSIZE = 1500;
const int ABSLIMIT = 9;
int A[ARRSIZE][ARRSIZE];
int B[ARRSIZE][ARRSIZE];
int AA[ARRSIZE][ARRSIZE];
int B8[ARRSIZE][ARRSIZE];
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
  int k = 0;
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
  // запускаем в расспараллеливание операцию А*A
  for (nthreads = 1; nthreads <=4; ++nthreads) {
    clock_timer = clock();
    wall_timer = omp_get_wtime();
    for (i = 0; i < ARRSIZE; i++)
    {
      for (j = 0; j < ARRSIZE; j++)
      {
        AA[i][j] = 0;
        #pragma omp parallel for num_threads(nthreads)  reduction(+:AA[i][j])
        for (k = 0; k < ARRSIZE; k++)
        {
          AA[i][j] += A[i][k] * A[k][i];
        }
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
    // запускаем в расспараллеливание операцию AA+B8+3
    #pragma omp parallel for num_threads(nthreads)
    for (i = 0; i < ARRSIZE; i++)
    {
      for (j = 0; j < ARRSIZE; j++)
      {
        RESULT[i][j] = AA[i][j] + B8[i][j] + 3;
      }
    }
    std::cout << "Использовано потоков: " << nthreads
    << ". Время выполнения вычислений: " <<  omp_get_wtime() - wall_timer << " сек" << "\n";
  }
  // printf("Result of calculates is\n");
  //  print_matrix(RESULT);

  return 0;
}
