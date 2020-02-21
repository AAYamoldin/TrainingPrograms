#include <stdio.h>

int main()
{

int c, adding;

while ((c = getchar()) != EOF) {
    adding = '\0';
      if (c == '\\') {
        c = '\\';
        adding = '\\';
        }    
    if (c == '\t') {
        c = '\\';
        adding = 't';
        }
    if (c == '\b') {
        c = '\\';
        adding = 'b';
        }
    putchar(c);
    putchar(adding);
    }
if (c == EOF)
    system("clear");
}

