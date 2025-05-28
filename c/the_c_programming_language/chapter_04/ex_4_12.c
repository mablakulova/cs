#include <stdio.h>

#define BUF_SIZE  100

void itoa(char s[], int n);

void itoa(char s[], int n) {
    static int buf_p = 0;

    if (n < 0) {
        s[buf_p++] = '-';
        n = -n;
    }

    if (n / 10)
       itoa(s, n / 10);
    if (buf_p < BUF_SIZE - 1) {
        s[buf_p++] = (n % 10 + '0');
        s[buf_p] = '\0';
    }
    else
       printf("Error: the string length limit reached!\n");
}

int main(void) {
    char s[BUF_SIZE];
    itoa(s, -123);

    printf("%s\n", s);
    return 0;
}