#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate
 * values from standard headers and by direct computation. Harder if you 
 * compute them: determine the ranges of the various floating-point types.
 */
int main(void)
{
    printf("The ranges from standard header:\n");

    printf("Minimum signed char %d\n", SCHAR_MIN);
    printf("Maximum signed char %d\n", SCHAR_MAX);
    printf("Minimum signed short int %d\n", SHRT_MIN);
    printf("Maximum signed short int %d\n", SHRT_MAX);
    printf("Minimum signed int %d\n", INT_MIN);
    printf("Maximum signed int %d\n", INT_MAX);
    printf("Minimum signed long int %ld\n", LONG_MIN);
    printf("Maximum signed long int %ld\n", LONG_MAX);
    printf("Minimum signed long long int %lld\n", LLONG_MIN);
    printf("Maximum signed long long int %lld\n", LLONG_MAX);

    printf("Minimum float %E\n", FLT_MIN);
    printf("Maximum float %E\n", FLT_MAX);
    printf("Minimum double %E\n", DBL_MIN);
    printf("Maximum double %E\n", DBL_MAX);
    printf("Minimum long double %LE\n", LDBL_MIN);
    printf("Maximum long double %LE\n", LDBL_MAX);

    printf("Maximum unsigned char %d\n", UCHAR_MAX);
    printf("Maximum unsigned short int %d\n", USHRT_MAX);
    printf("Maximum unsigned int %u\n", UINT_MAX);
    printf("Maximum unsigned long int %lu\n", ULONG_MAX);
    printf("Maximum unsigned long long int %llu\n", ULLONG_MAX);

    return 0;
}