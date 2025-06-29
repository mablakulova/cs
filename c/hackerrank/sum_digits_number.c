#include <stdio.h>

int main(void) {
    int a, rem, sum;
    scanf("%d", &a);

    sum = 0;
    while (a / 10) {
        sum += a % 10;
        a = a / 10;
    }
    sum += a;
    
    printf("%d\n", sum);
    return 0;
}