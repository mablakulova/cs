#include <stdio.h>

void _strcat1(char s[], char t[]);
void _strcat2(char *s, char *t);

void _strcat1(char s[], char t[]) {
    int i, j;

    for (i = 0; s[i] != '\0'; i++)
       ;
    for (j = 0; (s[i] = t[j]) != '\0'; i++, j++)
       ;
    s[i] = '\0';
}

void _strcat2(char *s, char *t) {
    while (*s != '\0') {
        s++;
    }
    while (*s++ = *t++)
       ;
}

int main(void) {
    char s1[] = "hello", t1[] = "world";
    char s2[] = "hello", t2[] = "world";

    _strcat1(s1, t1);
    _strcat2(s2, t2);

    printf("%s\n", s1);
    printf("%s\n", s2);
    return 0;
}