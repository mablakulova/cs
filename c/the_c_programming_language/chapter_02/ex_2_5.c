#include <stdio.h>

#define BUFFER_SIZE 1000

void get_line(char items[], int size);
int any(char s1[], char s2[]);

/* 
 * Exercise 2-5. Write the function any(s1, s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs, or -1 if s1
 * contains no characters from s2.
 */
int main(void) {
    char s1[BUFFER_SIZE], s2[BUFFER_SIZE];

    printf("Enter a string s1: \n");
    get_line(s1, BUFFER_SIZE);

    printf("Enter a string s2: \n");
    get_line(s2, BUFFER_SIZE);

    printf("The first location is %d\n", any(s1, s2));
    return 0;
}

void get_line(char items[], int size) {
    int c, idx;

    for (idx = 0; (c = getchar()) != EOF && c != '\n' && idx < size - 1; ++idx)
        items[idx] = c;

    items[idx] = '\0';
}

int any(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; ++i) {
        for (int j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}