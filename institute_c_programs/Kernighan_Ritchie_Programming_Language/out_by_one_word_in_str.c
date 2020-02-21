#include <stdio.h>

#define IN 1
#define OUT 0
#define OLD_WORD 0
#define NEW_WORD 1
int main()
{

int c, state, what_word;

while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',' || c == '!' || c == '?'){
        state = OUT;
        c = '\0';}
        
    else if (state == OUT) {
        state = IN;
        what_word = NEW_WORD;
           }
    if (what_word == NEW_WORD) {
        printf("\n");
        putchar(c);
        what_word = OLD_WORD;
        }
    else 
    putchar(c);
}
}

