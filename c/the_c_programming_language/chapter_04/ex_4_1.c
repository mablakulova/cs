#include <stdio.h>

int strrindex (char s[], char t[]);

int main() {
    printf("%d\n", strrindex("hello world hello", "hello"));
    printf("%d\n", strrindex("programming", "gr"));
    printf("%d\n", strrindex("abcdefg", "xyz"));
    printf("%d\n", strrindex("banana", "na"));
    printf("%d\n", strrindex("programming", "pro"));
    printf("%d\n", strrindex("apple", "a"));
    printf("%d\n", strrindex("a", "a"));
    printf("%d\n", strrindex("hello", ""));
    printf("%d\n", strrindex("hi", "hello"));
    printf("%d\n", strrindex("ab", "abc"));

    return 0;
}

int strrindex (char s[], char t[]) {
    int s_len, t_len;
    for (s_len = 0; s[s_len] != '\0'; s_len++)
      ;
    for (t_len = 0; t[t_len] != '\0'; t_len++)
      ;
    
    if (t_len == 0) {
        return -1;
    }
    
    int i, j;
    for (; s_len >= 0; s_len--) {
        for (i = s_len - 1, j = t_len - 1; t[j] == s[i] && j >= 0; j--, i--) 
           ;
        
        if (j == -1) {
            return i + 1;
        }
    }
    return -1;
}

/*int strrindex (char s[], char t[]) {
    int i, j, temp;
    int result = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0, temp = i; t[j] != '\0' && s[temp] == t[j]; j++, temp++)
           ;

        if (j > 0 && t[j] == '\0') {
            result = i;
        }
    }

    return result;
}*/