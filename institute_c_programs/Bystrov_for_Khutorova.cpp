#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#define _USE_GENERIC_MATH1
#include <math.h>
#include <unistd.h>

using namespace std;

// функция генерации случайного числа из диапазона от range_min до range_max включительно
int rrand(int range_min, int range_max) {
  return rand() % (range_max - range_min + 1) + range_min;
}

const unsigned int ARRSIZE = 10000;
const int ABSLIMIT = 9;

int A[ARRSIZE][ARRSIZE];
int B[ARRSIZE][ARRSIZE];
int RESULT[ARRSIZE][ARRSIZE];

// void  print_matrix(int A[][ARRSIZE])
// {
//   int i = 0;
//   int j = 0;
//   while (i < ARRSIZE)
//   {
//     while (j < ARRSIZE)
//     {
//       //   printf("%-5d ", A[i][j]);
//       j++;
//     }
//     j = 0;
//     i++;
//     // printf("\n");
//   }
// }

int main(void)
{
  int i = 0;
  int j = 0;
  int nthreads;
  clock_t clock_timer;
  double wall_timer;
  // Заполняем двумерные массивы A и В рандомными числами
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
  //запускаем в расспараллеливание операци сложения массивов
  for (nthreads = 1; nthreads <=4; ++nthreads) {
    clock_timer = clock();
    wall_timer = omp_get_wtime();
    #pragma omp parallel for num_threads(nthreads)
    for (i = 0; i < ARRSIZE; i++)
    {
      for (j = 0; j < ARRSIZE; j++)
      {
        RESULT[i][j] = tan(cos(sin(cos(tan(A[i][j] + B[i][j])))));
      }
    }
    std::cout << "Задействовано потоков: " << nthreads
    <<  " Время выполнения программы: " <<  omp_get_wtime() - wall_timer
    << " сек" << "\n";
  }

  return 0;
}
