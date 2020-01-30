#include <stdio.h>
#include <math.h>
  int  main() {
  float nizngr, verhgr, step;
  float a, rez;
  double  e = 2.718;
  a = 3 * log(3);
  printf("чувак введи нижнюю границу ");
  scanf ("%f", & nizngr);
  printf ("чувак введи веди верхнюю границу ");
  scanf ("%f", & verhgr);
  printf ("чувак введи шаг ");
  scanf ("%f", &  step);
  step = fabs(step);
 float r = verhgr;
 if (nizngr>verhgr){
 verhgr = nizngr;
 nizngr = r;
 };
 while ((verhgr-nizngr<step) || step == 0) {
 printf ("вонючий даун, шаг должен быть меньше  разности границ и не 0, вводи шаг заново ");
 scanf ("%f", & step);
 };
  while (nizngr <= verhgr)
  {
  double k = pow( e , a );
  double t = tan(( nizngr / a)-(nizngr / 6)) * M_PI / 180;
  t = pow( t, 3 );
  t = log (t);
  rez = k+t;
  printf("%f\t%f\n", nizngr, rez);
  nizngr = nizngr+step ;
  }
}
