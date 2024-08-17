#include <stdio.h>

#define IN  1
#define OUT 0

/* count lines, words, and characters in input */
int main()
{
    long c, nl, nw, nchars, state;
    nl = nw = nchars = 0;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        ++nchars;
        if (c == '\n')
          ++nl;
        if (c == '\n' || c == '\t' || c == ' ') {
            if (state)
              ++nw;
            state = OUT;
        } 
        else {
            state = IN;
        }
    }

    printf("The number of lines: %ld, words: %ld, characters: %ld\n", nl, nw, nchars);
    return 0;
}