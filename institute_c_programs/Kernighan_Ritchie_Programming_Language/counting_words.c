#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{

int c,num_lines,num_words,num_chars,state;

state = OUT;
num_words = num_chars = 0;
num_lines = 1;
while ((c = getchar()) != EOF) {
    ++num_chars;
    if (c == '\n')
        ++num_lines;
    if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',' || c == '!' || c == '?')
        state = OUT;
    else if (state == OUT) {
        state = IN;
        ++num_words;
        }
}
printf("\nlines: %d, words %d, chars: %d\n", num_lines, num_words, num_chars);

}
