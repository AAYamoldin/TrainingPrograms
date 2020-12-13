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

double f(double x, double y)
{
    return (exp(sin(3.141592*x)+cos(3.141592*y))+1)/16;
}

double func(double a1,double b1,double a2,double b2, int n1,int n2, int nthreads)
{
    double I=0,h1=(b1-a1)/n1,h2=(b2-a2)/n2;
    int how_many_x = (b1-a1)/h1;
    int how_many_y = (b2-a2)/h2;
    double x = a1, y=a2;
    #pragma omp parallel for num_threads(nthreads) reduction(+:I)
    for (int board1 = 0; board1<how_many_x; board1++)
    {
      for (int board2 = 0; board2<how_many_y;board2++)
      {
        I+=h1*h2*f(x+h1/2,y+h2/2);
        y+=h1;
      }
      x+=h1;
    }
        return I;

}



int main() {
clock_t clock_timer;
double wall_timer;
for (int nthreads = 1; nthreads <=4; ++nthreads) {
  // cout << "I = " << func(0,16,0,16,1000,1000, nthreads) << endl;
  clock_timer = clock();
  wall_timer = omp_get_wtime();
  std::cout << "Результат программы = " << func(0,16,0,16,40000,40000, nthreads) << " Количество потоков: " << nthreads << " Время выполнения: " <<  omp_get_wtime() - wall_timer << "сек" << "\n";
}

cout << "Результат истинный  = " << 41.6467599099991 << endl;
return 0;
}
