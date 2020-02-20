#include <stdio.h>

int main()
{
int c, space, tab, num_str;

space = 0;
tab = 0;
num_str = 0;

while ((c = getchar()) != EOF) {
    if (c == ' ')
        ++space;
    if (c == '\t')
        ++tab;
    if (c == '\n')
        ++num_str;        
    printf("\rspaces %d tabulation %d strings %d", space, tab, num_str);
    }
}
