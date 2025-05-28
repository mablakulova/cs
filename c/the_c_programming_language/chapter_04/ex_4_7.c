#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_OP      100
#define BUF_SIZE    100
#define NUMBER      '0'
#define MATH_FUNC   'F'

char buf[BUF_SIZE];
int buf_cnt = 0;

int getch(void);
void ungetch(int c);
void ungets(char s[]);

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

void ungets(char s[]) {
    int s_len = strlen(s);

    while (s_len-- > 0)
       ungetch(s[s_len]);
}

int get_op(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
       ;
    
    i = 0;
    if (!isdigit(c) && c != '.') {
        if ((c == '-' || c == '+') && isdigit(c = getch())) {
            s[++i] = c;
        } else if (c == 's' && (s[++i] = c = getch()) == 'i' && (s[++i] = c = getch()) == 'n') {
            s[++i] = '\0';
            return MATH_FUNC;
        } else if (c == 'e' && (s[++i] = c = getch()) == 'x' && (s[++i] = c = getch()) == 'p') {
            s[++i] = '\0';
            return MATH_FUNC;
        } else if (c == 'p' && (s[++i] = c = getch()) == 'o' && (s[++i] = c = getch()) == 'w') {
            s[++i] = '\0';
            return MATH_FUNC;
        } else {
            if (c != s[0])
               ungetch(c);
            s[1] = '\0';
            return s[0];
        }
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
           ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
           ;
    }

    s[i] = '\0';
    if (c != EOF)
       ungetch(c);
    return NUMBER;
}

int main(void) {
    char s[MAX_OP];
    ungets("123");
    int result = get_op(s);

    printf("%d\n", result == NUMBER);
    printf("%s\n", s);
    return 0;
}