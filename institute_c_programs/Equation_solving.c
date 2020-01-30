#include <stdio.h>
#include <math.h>
  int main()
{
  long double rez,k,F,a,b,z,t,x,y,l,s,c,f,L,S,C;


 t = pow(10, -9);
  printf ("функция на которой мы ищем корни f(x)= sin(ln x) – cos(ln x) + 2·ln x, она существует на промежутке (0; +бесконечность)\n");
  printf("ведите значение точки А отрезка АБ ");
  scanf("%Lf", & a);
  printf("введите значение точки Б отрезка АБ ");
  scanf("%Lf", & b);


 while (a<=0 || b<=0) {
  printf ("корней не сущ, под лог не мб отрицательного числа или нуля\n");
  printf("введите еще раз значение точки А ");
  scanf("%Lf", & a);
  printf("введите еще раз значение точки Б ");
  scanf ("%Lf", & b);
  }

  long double q = b;
   if (a>b)
   {
   b = a;
   a = q;
   };
   while (b-a<=t)
  {
  printf("любезный молодой человек, Вы задаёте слишком малый интервал, введите еще раз значение точки А ");
  scanf("%Lf", & a);
  printf("введите еще раз значение точки Б ");
  scanf ("%Lf", & b);
  };
  x = b;
  k = b-a;

  while ( k > t)
  {
  long double l = logl(a);
  long double s = sin(l);
  long double c = cos(l);
  long double f = s-c+2*l;

  long double L = logl(x);
  long double S = sin(L);
  long double C = cos(L);
  long double F = S-C+2*L;
  z = f;
  y = F;
  if (y*z>0)
  {
  a = x;
  }
  if (y*z<0) {
  b = x;
  }
  k = b-a;
  x = (a+b) / 2;

rez = x;}
if (rez == b){
printf ("на данном интервале корней нет\n ");
}
else {
printf ("koren v tochke  ");
printf ("%15Lf\n", rez );
}
}
