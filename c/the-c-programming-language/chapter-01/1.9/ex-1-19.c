#include <stdio.h>

#define BUFFER_SIZE 1000

int get_line(char items[], int size);
void reverse_array(char arr[], int size);

/* Exercise 1-19. Write a function reverse ( s} that reverses the character 
 * string s. Use it to write a program that reverses its input a line at a time. 
 */
int main()
{
    int current_size;
    char current_line[BUFFER_SIZE];

    while ((current_size = get_line(current_line, BUFFER_SIZE)) > 0) {
        reverse_array(current_line, current_size);
        printf("%s", current_line);
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

void reverse_array(char arr[], int size) 
{
    char temp;
    int idx, r_idx;

    for (idx = 0, r_idx = size-2; idx < (size-1) / 2; ++idx, r_idx--) {
        temp = arr[idx];
        arr[idx] = arr[r_idx];
        arr[r_idx] = temp;
    }
}