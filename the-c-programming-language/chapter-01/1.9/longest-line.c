#include <stdio.h>

#define BUFFER_SIZE 1000

int get_line(char items[], int size);
void copy(char to[], char from[]);

int main()
{
    int current_size, max_size;
    char current_line[BUFFER_SIZE];
    char max_line[BUFFER_SIZE];

    max_size = 0;
    while ((current_size = get_line(current_line, BUFFER_SIZE)) > 0) {
        if (current_size > max_size) {
            max_size = current_size;
            copy(max_line, current_line);
        }
    }

    if (max_size > 0) {
        printf("The size of longest line is %d\n", max_size);
        printf("The longest line is %s", max_line);
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

void copy(char to[], char from[]) 
{
    for (int i = 0; from[i] != '\0'; ++i) 
      to[i] = from[i];
}