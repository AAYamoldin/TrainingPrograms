#include <stdio.h>
#define IN_ARRAY 1
#define OUT_ARRAY 0


int main()
{
int c, i,state, symbols,chars[50], density[50];

state = OUT_ARRAY;
while ((c = getchar()) != EOF){
    for (i = 0; i < 50; ++i){
        state = OUT_ARRAY;        
            if (c == chars[i]){
            state = IN_ARRAY;
            ++density[i];
            i = 50;            
            }
        if (state == OUT_ARRAY){
            chars[i] = c;
            density[i] = 1;
            ++symbols;            
            }
             
        }
    }
i = 0;
c = 0;
for (i = 0; i < symbols; ++i){
    printf("\nсимвол %c гистограмма ", chars[i]);
    for (c = 0; c < density[i]; ++c){
        printf("-");
        }     
    }
}
