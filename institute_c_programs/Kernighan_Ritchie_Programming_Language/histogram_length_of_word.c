#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

int main()
{
int i,counter, c, state, num_chars[10], quantitywords;;/*максимальное кол-во слов 100*/

i = 0;
counter = 0;
state = OUT_WORD;
while ((c = getchar()) != EOF){
    if (c == ' ' || c == '\t' || c == '\n' || c == '!' || c == '?' || c == '.' || c == ','){
            if (state == IN_WORD){
            num_chars[i] = counter;
            ++i;            
            }
        state = OUT_WORD;
        counter = 0;        
        }
    else if (state == OUT_WORD){
        state = IN_WORD;
        }
    if (state == IN_WORD)
        ++counter; 
    }
quantitywords = i;
printf("\ntotal words: %d", quantitywords);
i = 0;
state = 0;
for ( i = 0; i < quantitywords; ++i){
        if (num_chars[i] != 0){
            printf("\n");
            printf("в %d слове %d символов  ", i+1, num_chars[i]); 
            for (state = 0; state < num_chars[i]; ++state){
                printf("-");
                }
            }        
        }
    
printf("\n");
}

