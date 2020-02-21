#include <stdio.h>

int main()
{

int c, counter;

counter = 0;

while ((c = getchar()) != EOF) {
    if (c != ' ')
    counter = 0;    
    if (c == ' ')
        ++counter;
    if (counter > 1)
        c = '\0';    
    putchar(c);
    }
if (c == EOF)
    system("clear");
}
