#include <stdio.h>
#include <math.h>
  int main()
{
  float int3, dx, dx1 ,x, x1 , n, eps, i, prom, s, s1, f, f1, rez, i1, prom1, rez1, int2, int1;

  printf ("функция от которою мы раскладываем в ряд f(x) = ln(1-x)\n ");


  printf("  ведите значение переменной х ");
  scanf("%f", & x);

  while (x>=1){
  printf (" f(x) = ln(1-x) определена на (-беск; 1)\n");
  printf (" введите значение х ");
  scanf ("%f", & x);
  }

  printf ("  введите номер n  конечного члена разбиения ряда  ");
  scanf ("%f", & n);

  while (n -floorl(n) != 0 || n<0) {
  printf ("  конечное число разбиения должно быть натуральным!\n");
  printf("введите ещё раз значие числа разбиений ");
  scanf("%f", & n);
  }
 // printf("точность вычислений не может быть отрицательной\n");
 //printf ("введите еще раз значение точности вычислений ");
 // scanf ("%f", & eps);

  eps = 0.000001;


   i = 1;
  rez1 = 0;
  rez = 0;
  int1 = 0;
  int2 = 1;
  dx = 0;
 while (i<n) {
  dx = pow ( x, i);
  s = dx/i;
  f = s + rez;
  rez = f;
  i = i + 1;
  }
  int3  = 1*  rez;

while ( fabs(int2-int1) > eps){

  while (i<n) {
  dx = pow ( x, i);
  s = dx/i;
  f = s + rez;
  rez = f;
  i = i + 1;
  }
  int1  = 1*  rez;
 // printf ("%f\n", int1);

  i1 = 1;
  rez1 = 0;
  n = 2 * n;
  dx1 = 0;

while (i1<n) {
  dx1 = pow ( x, i1);
  s1 = dx1/i1;
  f1 = s1 + rez1;
  rez1 = f1;
  i1 = i1 + 1;
  }
  int2 = 1* rez1;
//  printf ("%f\n", rez1);
}
  printf ("  сумма ряда для заданного значения \n");
  printf ("%f\n", int3);
  printf ("  сумма ряда для заданной точности \n");
  printf ("%f\n", int2);
  printf ("  колличество членов при заданной точности \n");
  printf ("%f\n", n);
}
