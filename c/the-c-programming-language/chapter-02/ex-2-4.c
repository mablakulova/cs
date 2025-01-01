#include <stdio.h>

#define BUFFER_SIZE 1000

void get_line(char items[], int size);
void squeeze(char s1[], char s2[]);

/* Exercise 2-4. Write an alternate version of squeeze (s1, s2) that
 * deletes each character in s1 that matches any character in the string s2.
 */
int main(void)
{
    char s1[BUFFER_SIZE], s2[BUFFER_SIZE];

    printf("Enter a string s1: \n");
    get_line(s1, BUFFER_SIZE);

    printf("Enter a string s2: \n");
    get_line(s2, BUFFER_SIZE);

    squeeze(s1, s2);

    printf("After squeezing s1: %s\n", s1);
    return 0;
}

void get_line(char items[], int size) 
{
    int c, idx;

    for (idx = 0; (c = getchar()) != EOF && c != '\n' && idx < size - 1; ++idx)
        items[idx] = c;

    items[idx] = '\0';
}

void squeeze(char s1[], char s2[])
{
    int rIdx = 0, canInclude = 1;
    for (int i = 0; s1[i] != '\0'; ++i)
    {
        for (int j = 0; s2[j] != '\0'; ++j)
        {
            if (s1[i] == s2[j])
            {
                canInclude = 0;
                break;
            }
        }

        if (canInclude)
          s1[rIdx++] = s1[i];

        canInclude = 1;
    }

    s1[rIdx] = '\0';
}