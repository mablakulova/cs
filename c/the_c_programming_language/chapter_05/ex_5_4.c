#include <stdio.h>

int strend(char *s, char *t);

int strend(char *s, char *t) {
    char *s_start = s, *t_start = t;
    
    while (*s != '\0')
       s++;
    while (*t != '\0')
       t++;
    
    for (; *s == *t; s--, t--) {
        if (t == t_start)
           return 1;
    }
    return 0;
}

int main(void) {
    char s1[] = "helloworld", t1[] = "world";
    char s2[] = "abcde", t2[] = "ef";
    char s3[] = "e", t3[] = "ef";

    printf("%d\n", strend(s1, t1));
    printf("%d\n", strend(s2, t2));
    printf("%d\n", strend(s3, t3));
    return 0;
}