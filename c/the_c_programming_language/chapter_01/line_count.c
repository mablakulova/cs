#include <stdio.h>

/* count lines in input */
int main() {
    long c, nl;

    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
          ++nl;
    }

    printf("The number of lines in input is %ld\n", nl);
    return 0;
}