#include <stdio.h>

#define BUF_SIZE    100

int buf[BUF_SIZE];
int buf_cnt = 0;

int getch(void);
void ungetch(int c);

int getch(void) {
    if (buf_cnt > 0)
       return buf[--buf_cnt];
    else
       return getchar();
}

void ungetch(int c) {
    if (buf_cnt < BUF_SIZE)
       buf[buf_cnt++] = c;
    else
       printf("Error: character buffer is full\n");
}

int main(void) {
    ungetch(EOF);
    printf("%d\n", getch());

    return 0;
}