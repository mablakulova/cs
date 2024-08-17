#include <stdio.h>

/* Exercise 1-9. Write a program to copy its input to its output, replacing each 
 * string of one or more blanks by a single blank. 
 */
int main()
{
    long c, s_blank;
    
    s_blank = 1;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
        {
            if (s_blank)
              putchar(c);
            s_blank = 0;
        }
        else {
            putchar(c);
            s_blank = 1;
        }
    }
    return 0;
}