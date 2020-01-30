#include <stdio.h>
#include <math.h>
  int main()
{
  float int1, int2, a, b, eps, k, t, p, interval,  interval1, e, s1, s2, f, F, n;

  printf ("функция от которой мы ищем интеграл f(x) = sqrt 1+x2\n");
  printf("ведите значение нижней границы ");
  scanf("%f", & a);

  printf("введите значение верхней границы ");
  scanf("%f", & b);

  printf (" введите начальное число разбиений \n");
  scanf ("%f", & n);
  eps = 0.0001;
 // printf ("введите значение точности вычислений \n");
 // scanf ("%f", & eps);

  while (n - floorl(n) != 0 || ( n<=0 || eps<=0)) {
  printf ("число разбиений не может быть отрицательным или не целым!\n");
  printf("введите ещё раз значие числа разбиений ");
  scanf("%f", & n);
  printf("точность вычислений не может быть отрицательной\n");
  printf ("введите еще раз значение точности вычислений ");
  scanf ("%f", & eps);
  }


 //k = 0;
 //interval = 0;
 //t = n;
 //s1 = 0;
  int1 = 0;
  int2 = 1;
  //printf ("%f\%f\%f\%f\%f\n", s1, s2, k, t,  interval);

while ( fabs(int2-int1) > eps){

  k = 0;
  interval = 0;
  t = n;
  s1 = 0;

  while (k<t){
  f = sqrt (1+ (a+ k *  interval) *(a+ k * interval) );
  s1 = f+s1;
  int1 = s1;
  k = k+1;
  interval = ((b - a)/n);
  };
 // printf ("%f\%f\%f\n", s1, k, interval);

  s1 = s1 * interval;
  int1 = s1;
//  printf ("%f\n", s1);


  p = 0;
  interval1 = 0;
  n = 2 * n;
  e = n;
  s2 = 0;

  while (p<e){
  F = sqrt (1+ (a+ p *  interval1) *(a+ p * interval1) );
  s2 = F+s2;
  p = p+1;
  int2 = s2;
  interval1 = ((b - a)/n);
  };
  s2 = s2 * interval1;
  int2 = s2;
}
 // printf ("%f\n", s2);
  printf ("интеграл равен ");
  printf ("%.5f\n", s2);
  printf ("число разбиений при которых была достигнута требуемая точность ");
  printf ("%.0f\n", n);
}
