#include <stdio.h>

#define MAX_LINE  1000
#define TAB_STOP  8

int get_line(char s[], int line_size);

int get_line(char s[], int line_size) {
    int c, cnt, blank_cnt;
    
    cnt = 0;
    while (cnt < line_size - 1 && (c = getchar()) != EOF && c != '\n') {
        if (c == '\t') {
            blank_cnt = TAB_STOP - (cnt % TAB_STOP);
            while (blank_cnt-- > 0)
               s[cnt++] = ' ';
        } else 
            s[cnt++] = c;
    }
    if (c == '\n') {
        s[cnt++] = c;
    }
    s[cnt] = '\0';
    return cnt;
}

int main(void) {
    char s[MAX_LINE];

    while (get_line(s, MAX_LINE) > 0) {
        printf("%s", s);
    }
    return 0;
}