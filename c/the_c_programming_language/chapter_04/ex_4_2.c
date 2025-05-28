#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

int main(void) {
   double result = atof("123.45e-6");
   printf("Output: %g\n", result);

   return 0;
}

double atof(char s[]) {
   double val, power;
   int i, sign, exp;

   for (i = 0; isspace(s[i]); i++)
      ;
   sign = (s[i] == '-') ? -1 : 1;

   if (s[i] == '+' || s[i] == '-')
      i++;
   for (val = 0.0; isdigit(s[i]); i++) {
      val = 10.0 * val  + (s[i] - '0');
   }
    
   if (s[i] == '.')
      i++;
   for (power = 1.0; isdigit(s[i]); i++) {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
   }
   val = sign * val / power;

   if (s[i] == 'e' || s[i] == 'E') {
      sign = (s[++i] == '-') ? -1 : 1;
      if (s[i] == '+' || s[i] == '-')
         i++;

      for (exp = 0; isdigit(s[i]); i++) {
         exp = 10 * exp + (s[i] - '0');
      }

      for (; exp > 0; exp--) {
         if (sign == 1) {
            val *= 10.0;
         } else {
            val *= 0.1;
         }
      }
   }
   
   return val;
}