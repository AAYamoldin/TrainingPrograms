#include<stdio.h>

int main()
{

float celsius, fahr;
int lower,upper,step;

lower = 0;
upper = 150;
step = 15;
fahr = lower;

printf("convert fahr to celsius\n");
while (fahr <= upper){
    celsius = (5.0/9.0) * (fahr-32.0);    
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
    }
}
