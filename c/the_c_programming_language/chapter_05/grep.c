#include <stdio.h>
#include <string.h>

#define MAXLINE  1000

int _getline(char *s, int maxline);

int _getline(char *s, int maxline) {
    int c;
    char *s_start = s;

    while (--maxline > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    if (c == '\n')
       *s++ = c;
    *s = '\0';
    return s - s_start;
}

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2) {
        printf("Usage: find pattern\n");
    } else {
        while (_getline(line, MAXLINE) > 0) {
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
        }
    }

    printf("Matching lines count is %d\n", found);
    return 0;
}