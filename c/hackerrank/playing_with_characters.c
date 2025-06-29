#include <stdio.h>

#define MAX_LEN  100

int main(void) {
    char c, str[MAX_LEN], sentence[MAX_LEN];
    scanf("%c %99s \n %[^\n]%*c", &c, str, sentence);

    printf("%c\n", c);
    printf("%s\n", str);
    printf("%s\n", sentence);
    return 0;
}