#include <stdio.h>

char *_strncpy(char *s, char *t, int n);
char *_strncat(char *s, char *t, int n);
int _strncmp(char *s, char *t, int n);

char *_strncpy(char *s, char *t, int n) {
    char *s_start = s; 
    while (n-- > 0){
        *s++ = *t ? *t++ : '\0';
    }
    return s_start;
}

char *_strncat(char *s, char *t, int n) {
    char *s_start = s; 
    while (*s != '\0') {
        s++;
    }
    while (n-- > 0 && (*s = *t) != '\0') {
        s++;
        t++;
    }

    *s = '\0';
    return s_start;
}

int _strncmp(char *s, char *t, int n) {
    while (n-- > 0) {
        if (*s != *t)
           return *s - *t;
        if (*s == '\0')
           break;
    
        s++;
        t++;
    }
    return 0;
}

int main(void) {
    char s1[] = "abcdef", t1[] = "qmnl";
    char s2[] = "hello", t2[] = "world";
    char s3[] = "hello", t3[] = "hello";

    _strncpy(s1, t1, 3);
    _strncat(s2, t2, 3);

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%d\n", _strncmp(s3, t3, 6));

    return 0;
}