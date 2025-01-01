#include <stdio.h>

#define HEX_CHAR_LINE 18

long long htoi(char s[]);

/* Exercise 2-3. Write the function htoi (s), which converts a string of 
 * hexadecimal digits (including an optional 0X or 0x) into its equivalent 
 * integer value. The allowable digits are 0 through 9, a through f, and A through F.
 */
int main(void)
{
    char s[HEX_CHAR_LINE+1];
    int i, c;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < HEX_CHAR_LINE; ++i)
       s[i] = c;

    s[i] = '\0';
    
    long long n = htoi(s);
    if (n == -1)
      printf("Error: %s is not valid hexadecimal value\n", s);
    else
      printf("Hexadecimal value: %lld\n", n);
    
    return 0;
}

long long htoi(char s[])
{
    int i, hexDigit;
    long long result = 0;

    i = 0;
    if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
    {
        i += 2;
    }
    
    for (; s[i] != '\0'; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
           hexDigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
           hexDigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
           hexDigit = s[i] - 'A' + 10;
        else
           return -1;
        
        result = 16 * result + hexDigit;
    }

    return result;
}