#include <stdio.h>

#define MAX_LINE  1000
#define TAB_STOP  8

int get_line(char s[], int line_size);

int get_line(char s[], int line_size) {
    int c, idx, c_cnt, blank_cnt;

    idx = 0, c_cnt = 0, blank_cnt = 0;
    while (idx < line_size - 1 && (c = getchar()) != EOF && c != '\n') {
        c_cnt++;
        if (c == ' ') {
            blank_cnt++;
            if (c_cnt % TAB_STOP == 0 && blank_cnt > 1) {
                idx = idx - blank_cnt + 1;
                s[idx++] = '\t';
                blank_cnt = 0;
            } else {
                s[idx++] = c;
            }
        } else {
            s[idx++] = c;
            blank_cnt = 0;
        }
    }
    
    if (c == '\n') {
        s[idx++] = c;
    }
    s[idx] = '\0';
    return idx;
}

int main(void) {
    char s[MAX_LINE];

    while (get_line(s, MAX_LINE) > 0) {
        printf("%s", s);
    }
    return 0;
}