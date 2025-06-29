#include <stdio.h>

int s_sum(int a, int b, int c, int n) {
    if (n == 1)
       return a;
    else if (n == 2)
       return b;
    else if (n == 3)
       return c;
    else
       return s_sum(a, b, c, n-1) + s_sum(a, b, c, n-2) + s_sum(a, b, c, n-3);
}

int main(void) {
    int a, b, c, n;
    scanf("%d %d %d %d", &n, &a, &b, &c);

    int sum = s_sum(a, b, c, n);
    printf("%d\n", sum);
    return 0;
}