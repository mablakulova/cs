#include <stdio.h>

#define AR_LENGTH  1000

int get_line(char items[], int size);
void squeeze(char s1[], char s2[]);

/* Exercise 2-4. Write an alternate version of squeeze (s1, s2) that
 * deletes each character in s1 that matches any character in the string s2.
 */
int main(void)
{
    char s1[AR_LENGTH], s2[AR_LENGTH];
    printf("Enter a string s1: \n");
    get_line(s1, AR_LENGTH);

    printf("\nEnter a string s2: \n");
    get_line(s2, AR_LENGTH);

    squeeze(s1, s2);

    printf("\nAfter squeezing s1: %s\n", s1);

    return 0;
}

int get_line(char items[], int size) 
{
    int c, idx;

    for (idx = 0; (c = getchar()) != EOF && idx < size - 1 && c != '\n'; ++idx) {
        items[idx] = c;
    }

    if (c == '\n')
      items[idx++] = c;

    items[idx] = '\0';
    return idx;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    k = 0;
    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; (s1[i] != s2[j]) && s2[j] != '\0'; ++j)
          ;
        
        if (s2[j] == '\0')
          s1[k++] = s1[i];
    }

    s1[k] = '\0';
}