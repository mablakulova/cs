#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    *a = *a + *b;
    *b = abs(*a - 2 * (*b));
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    update(&a, &b);
    printf("%d\n%d\n", a, b);
    return 0;
}