#include <stdio.h>

#define NUMBER_DIGIT 10

/* count digits, white space, others */
int main() {
    long c, i, nspace, nothers;
    nspace = nothers = 0;

    int digitarr[NUMBER_DIGIT];

    for (i = 0; i < NUMBER_DIGIT; ++i) 
      digitarr[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
           ++digitarr[c - '0'];
        else if (c == '\n' || c == '\t' || c == ' ')
           ++nspace;
        else
           ++nothers;
    }

    for (i = 0; i < NUMBER_DIGIT; ++i)
      printf("Number of digit: %ld is %d\n", i, digitarr[i]);
    
    printf("Number of white spaces is %ld, and others is %ld\n", nspace, nothers);
    return 0;
}