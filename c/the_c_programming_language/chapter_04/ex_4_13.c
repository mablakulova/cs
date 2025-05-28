#include <stdio.h>
#include <string.h>

void reverse(char s[]);

void reverse(char s[]) {
    static int i = 0;
    int len = strlen(s);
    
    char temp = s[i];
    s[i] = s[len-i-1];
    s[len-i-1] = temp;

    if (++i < len / 2)
       reverse(s);
    else 
       i = 0;
}

int main(void) {
    char s1[] = "hello";
    char s2[] = "world";
    
    reverse(s1);
    printf("%s\n", s1);
    
    reverse(s2); 
    printf("%s\n", s2);
    
    return 0;
}