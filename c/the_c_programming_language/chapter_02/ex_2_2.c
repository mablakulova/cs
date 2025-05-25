#include <stdio.h>

#define BUFFER_SIZE 1000

char current_line[BUFFER_SIZE];
char max_line[BUFFER_SIZE];

int get_line(void);
void copy(void);

/* 
 * Exercise 2-2. 
 * Write a loop equivalent to the for loop above without using && or || 
 */
int main(void) {
    int current_size, max_size;

    max_size = 0;
    while ((current_size = get_line()) > 0) {
        if (current_size > max_size) {
            max_size = current_size;
            copy();
        }
    }

    if (max_size > 0) {
        printf("The size of longest line is %d\n", max_size);
        printf("The longest line is %s", max_line);
    }
    return 0;
}

int get_line() {
    int c, idx;

    for (idx = 0; idx < BUFFER_SIZE - 1; ++idx) {
        c = getchar();
        if (c == EOF) {
            break;
        }

        if (c == '\n') {
            break;
        }

        current_line[idx] = c;
    }

    if (c == '\n')
      current_line[idx++] = c;

    current_line[idx] = '\0';
    return idx;
}

void copy() 
{
    for (int i = 0; current_line[i] != '\0'; ++i) 
       max_line[i] = current_line[i];
}