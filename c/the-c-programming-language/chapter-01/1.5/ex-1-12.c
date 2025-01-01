#include <stdio.h>

#define IN   1
#define OUT  0

/* Exercise 1-12. Write a program that prints its input one word per line. */
int main()
{
    long c, state;
    
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            if (state)
              printf("\n");
            state = OUT;
        }
        else {
            state = IN;
            putchar(c);
        }
    }

    return 0;
}