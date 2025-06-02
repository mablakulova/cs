#include <ctype.h>
#include <stdio.h>

#define BUF_SIZE   100
#define ARR_SIZE   100

int buf[BUF_SIZE];
int buf_cnt = 0;

int getch(void);
void ungetch(int c);
int getint(int *pn);

int getch(void) {
   if (buf_cnt > 0)
      return buf[--buf_cnt];
   else
      return getchar();
}

void ungetch(int c) {
   if (buf_cnt < BUF_SIZE)
      buf[buf_cnt++] = c;
   else
      printf("Error: character buffer is full\n");
}

int getint(int *pn) {
   int c, sign, c_temp;
   while (isspace(c = getch()))
      ;
   
   if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
      ungetch(c);
      return 0;
   }
   
   sign = (c == '-') ? -1 : 1;
   if (c == '+' || c == '-') {
      if (!isdigit(c_temp = getch())) {
         ungetch(c);
         if (c_temp != EOF)
            ungetch(c_temp);
         return 0;
      }
      c = c_temp;
   }
   
   for (*pn = 0; isdigit(c); c = getch())
      *pn = 10 * *pn + (c - '0');
   *pn *= sign;

   if (c != EOF)
      ungetch(c);
   return c;
}

int main(void) {
   int n, arr[ARR_SIZE];
   for (n = 0; n < ARR_SIZE && getint(&arr[n]) != EOF; n++)
      ;

   for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
   return 0;
}