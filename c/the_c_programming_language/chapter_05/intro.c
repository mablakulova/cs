#include <stdio.h>

int main(void) {
    int x;   // int called "x"
    int *y;  // pointer to an int (or "int-pointer"), called "y"
    int z;   // int called "z"

    x = 3490;   // assign 3490 to x
    y = &x;     // assign "the address of x" to y
    
    // at this point "y points to x".

    // the dereference, which says "z is assigned the value
    // of the thing y is pointing at"
    z = *y;

    printf("%d\n", z);
    return 0;
}