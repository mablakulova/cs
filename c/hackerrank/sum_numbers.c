#include <stdio.h>

int main(void) {
    int n1, n2;
    float f1, f2;
    scanf("%d %d %f %f", &n1, &n2, &f1, &f2);

    printf("%d %d\n", n1+n2, n1-n2);
    printf("%0.1f %0.1f\n", f1+f2, f1-f2);
    return 0;
}