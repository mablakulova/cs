#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define S_SIZE 1000

int main(void) {
    char *str_ptr, *str_input = malloc(S_SIZE);
    int i, d_freq[10];
    scanf("%s", str_input);

    for (i = 0; i < 10; i++) {
        d_freq[i] = 0;
    }
    str_ptr = str_input;
    while (*str_ptr) {
        if(isdigit(*str_ptr))
           d_freq[*str_ptr-'0']++;
        str_ptr++;
    }

    for (i = 0; i < 10; i++) {
        printf("%d%s", d_freq[i], (i == 9) ? "\n": " ");
    }
    free(str_input);
    return 0;
}