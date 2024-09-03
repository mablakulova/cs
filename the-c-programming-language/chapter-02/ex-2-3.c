#include <stdio.h>

#define HEX_STR_SIZE 16

int htoi (char s[], int size);
int pow_base(int base, int p);

/* Exercise 2-3. Write the function htoi (s), which converts a string of 
 * hexadecimal digits (including an optional 0X or 0x) into its equivalent 
 * integer value. The allowable digits are 0 through 9, a through f, and A through F.
 */
int main(void)
{
    int c, idx;
    char buf[HEX_STR_SIZE];
    printf("Please enter valid hexadecimal value:\n");

    idx = 0;
    for (int i = 0; (c = getchar()) != EOF && idx < HEX_STR_SIZE; ++i) {
        if (c == '0' && i == 0) 
          continue;
        if (i == 1 && (c == 'x' || c == 'X'))
          continue;
        
        if ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'f') ||
            (c >= 'A' && c <= 'F')) {
                buf[idx++] = c;
        } else {
            printf("%c is not valid hexadecimal digit\n", c);                                                                                                                                                                           
            return 1;  
        }
    }

    printf("\nThe converted decimal value is %d\n", htoi(buf, idx));
    return 0;
}

int htoi (char s[], int size) {
    int digit, result;

    result = 0;
    for (int i = 0; i < size; ++i) {
        if (s[i] >= 'a' && s[i] >= 'f') {
            digit = s[i] - 'a' + 10;
        }

        if (s[i] >= 'A' && s[i] >= 'F') {
            digit = s[i] - 'A' + 10;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            digit = s[i] - '0';
        }

        result += digit * pow_base(16, size - i - 1);
    }
    return result;
}

int pow_base(int base, int p) {
    int result = 1;
    for (int i = 0; i < p; ++i) {
        result *= base;
    }

    return result;
}