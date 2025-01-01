#include <stdio.h>

#define LIMIT_SIZE 5
#define BUFFER_SIZE 1000

int get_line(char items[], int size);

/* Exercise 1-17. Write a program to print all input lines 
 * that are longer than 80 characters. 
 */
int main() 
{
    int current_size;
    char line[BUFFER_SIZE];

    while ((current_size = get_line(line, BUFFER_SIZE)) > 0) {
        if (current_size > LIMIT_SIZE) 
           printf("%s", line);
    }

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