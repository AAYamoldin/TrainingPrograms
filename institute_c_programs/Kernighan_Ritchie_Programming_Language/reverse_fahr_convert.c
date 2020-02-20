#include<stdio.h>

int main()
{
int fahr;

printf("reverse converting fahr to celsius\n");
for (fahr = 300; fahr >= 0; fahr = fahr - 30)
    printf("%3d\t%6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
} 
