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
    long linen = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if (argc != 1)
       printf("Usage: find -x -n pattern\n");
    else {
        while (_getline(line, MAXLINE) > 0) {
            linen++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                   printf("%ld:", linen);
                printf("%s", line);
                found++;
            }
        }
    }
    return 0;
}