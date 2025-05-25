#include <stdio.h>

/* 
 * Exercise 1-4. Write a program to print the corresponding 
 * Celsius to Fahrenheit table. 
 */
int main() {
    float fahr, celsius; 
    int lower, upper, step; 

    lower = 0;    /* lower limit of temperature table */ 
    upper = 200;  /* upper limit */ 
    step = 5;    /* step size */ 
    
    printf("Celsius\tFahrenheit\n");
    printf("-------------------\n");

    celsius = lower; 
    while (celsius <= upper) { 
        fahr = (9.0 / 5.0) * celsius + 32.0; 
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;  
    }

    return 0;
}