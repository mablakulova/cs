#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LAST_LINES 10
#define MAX_LINE   1000
#define MAX_LINES  1000

int _getline(char *s, int n) {
    int cnt;
    char c;

    cnt = 0;
    while (cnt < n-1 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        cnt++;
    }
    if (c == '\n') {
        *s++ = c;
        cnt++;
    }
    
    *s = '\0';
    return cnt;
}

int main(int argc, char *argv[]) {
    int t_lines, n_lines, l_idx, l_len, i;
    char *buf, *buf_p, *buf_end;
    char line[MAX_LINE];
    char *lines[MAX_LINES];

    if (argc == 1) {
        t_lines = LAST_LINES;
    } else if (argc == 2 && (*++argv)[0] == '-') {
        t_lines = atoi(argv[0] + 1);
    } else {
        printf("Usage: tail pattern\n");
        return 1;
    }

    if ((buf = buf_p = malloc(t_lines * MAX_LINE)) == NULL) {
        printf("Error: cannot allocate memory!\n");
        return 1;
    }
    buf_end = buf + t_lines * MAX_LINE;
    for (i = 0; i < t_lines; i++)
       lines[i] = NULL;

    n_lines = 0, l_idx = 0;
    while ((l_len = _getline(line, MAX_LINE)) > 0) {
        if (buf_p + l_len + 1 >= buf_end)
           buf_p = buf;
        lines[l_idx] = buf_p;
        strcpy(lines[l_idx], line);
        if (++l_idx >= t_lines)
           l_idx = 0;
        buf_p += l_len + 1;
        n_lines++;
    }

    i = 0;
    while (lines[i] != NULL) {
        printf("%s", lines[i]);
        i++;
    }
    return 0;
}