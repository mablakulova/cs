#include <stdio.h>

#define swap(t, x, y)   {  t (z);     \
                           (z) = (x); \
                           (x) = (y); \
                           (y) = (z); }

int main(void) {
    int a = 5, b = 10;
    swap(int, a, b);
    
    char c1 = 'A', c2 = 'Z';
    swap(char, c1, c2);
    
    float f1 = 3.14, f2 = 2.71;
    swap(float, f1, f2);
    
    double d1 = 1.234, d2 = 5.678;
    swap(double, d1, d2);
    
    int arr[] = {1, 2, 3, 4, 5};
    swap(int, arr[0], arr[4]);

    return 0;
}