#include <stdio.h>

/* count characters in input; 2nd version */
int main()
{
    long nc;
    for (nc = 0; (nc = getchar()) != EOF; ++nc)
       ;

    printf("The number of characters is %ld\n", nc);
    return 0;
}