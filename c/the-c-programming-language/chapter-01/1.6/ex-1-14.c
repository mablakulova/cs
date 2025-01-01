#include <stdio.h>

#define MAX_CHARS  128

/* Exercise 1-14. Write a program to print a histogram of the frequencies 
 * of different characters in its input. 
 */
int main()
{
    long c, i;
    int chararr[MAX_CHARS];

    for (i = 0; i < MAX_CHARS; ++i)
      chararr[i] = 0;
    
    while ((c = getchar()) != EOF)
        ++chararr[c];

    for (i = 0; i < MAX_CHARS; ++i)
       printf("The number of %ldth ASCII character is %d\n", i, chararr[i]);

    return 0;
}