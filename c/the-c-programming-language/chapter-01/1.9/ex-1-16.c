#include <stdio.h>

#define BUFFER_SIZE 1000

int get_line(char items[], int size);
void copy(char to[], char from[]);

/* Exercise 1-16. Revise the main routine of the longest-line program so it will 
 * correctly print the length of arbitrarily long input lines, and as much as 
 * possible of the text. 
 */
int main()
{
    char c;
    int current_size, max_size;
    char current_line[BUFFER_SIZE];
    char max_line[BUFFER_SIZE];

    max_size = 0;
    while ((current_size = get_line(current_line, BUFFER_SIZE)) > 0) {
        if (current_line[current_size - 1] != '\n') {
            while((c = getchar()) != EOF && c != '\n')
                ++current_size;
        }

        if (current_size > max_size) {
            max_size = current_size;
            copy(max_line, current_line);
        }
    }

    if (max_size > 0) {
        printf("The size of longest line is %d\n", max_size);
        printf("The longest line is %s\n", max_line);
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