#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, n, *in_arr;

    scanf("%d", &n);
    if ((in_arr = malloc(sizeof(int) * n)) == NULL)
       return 1;
    for (i = 0; i < n; i++) {
        scanf("%d", (in_arr+i));
    }

    int *arr_start = in_arr, *arr_end = in_arr + n - 1;
    while (arr_start < arr_end) {
        int temp = *arr_start;
        *arr_start = *arr_end;
        *arr_end = temp;

        arr_start++;
        arr_end--;
    }

    for (i = 0; i < n; i++) {
        printf("%d%s", *(in_arr+i), (i == n-1) ? "\n" : " ");
    }
    free(in_arr);
    return 0;
}