#include <stdio.h>

#define BUFFER_SIZE 1000

int get_line(char items[], int size);

/* Exercise 1-18. Write a program to remove trailing blanks and tabs 
 * from each line of input, and to delete entirely blank lines.
 */
int main()
{
    int current_size;
    char current_line[BUFFER_SIZE];

    while ((current_size = get_line(current_line, BUFFER_SIZE)) > 0) {
        printf("%s", current_line);
    }

    return 0;
}

int get_line(char items[], int size) 
{
    int c, idx, is_value;
    is_value = 0;

    for (idx = 0; (c = getchar()) != EOF && idx < size - 1 && c != '\n'; ++idx) {
        items[idx] = c;
    }

    while (idx > 0) {
        if (items[idx-1] == '\t' || items[idx-1] == ' ') {
             --idx;
        } else {
            if (c == '\n')
              items[idx++] = c;

            items[idx] = '\0';
            return idx;
        }
    }

    return 0;
}