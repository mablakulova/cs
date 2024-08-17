#include <stdio.h>

/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */
int main()
{
    long c, nblanks, ntabs, nlines;
    nblanks = ntabs = nlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
          ++nblanks;
        if (c == '\t')
          ++ntabs;
        if (c == '\n')
          ++nlines;
    }

    printf("Number of blanks: %ld, tabs: %ld, newlines: %ld\n", nblanks, ntabs, nlines);
    return 0;
}