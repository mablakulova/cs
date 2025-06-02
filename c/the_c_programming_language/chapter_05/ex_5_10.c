#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK   100
#define NUMBER      '0'

double stack[MAX_STACK];
int stack_cnt = 0;

void push(double f);
double pop(void);
int getop(char *s, char *op);

void push(double f) {
    if (stack_cnt < MAX_STACK)
       stack[stack_cnt++] = f;
    else
       printf("Error: stack is full!\n");
}

double pop(void) {
    if (stack_cnt > 0)
       return stack[--stack_cnt];
    else
       printf("Error: stack is empty!\n");
       return 0.0;
}

int getop(char *s, char *op) {
    int c;
    
    while ((c = *op = *s++) == ' ' || c == '\t')
       ;
    if (!isdigit(c) && c != '.') {
        *++op = '\0';
        return c;
    }

    if (isdigit(c)) {
        while (isdigit(c = *++op = *s++))
           ;
    }
    if (c == '.') {
        while (isdigit(c = *++op = *s++))
           ;
    }
    *op = '\0';
    return NUMBER;
}

int main(int argc, char *argv[]) {
    int type;
    char *op;
    double d2;
   
    if (argc == 1) {
        printf("Usage: expr pattern\n");
    } else {
        while (--argc > 0 && (type = getop(*++argv, op)) != EOF) {
            switch (type) {
                case NUMBER:
                   push(atof(op));
                   break;
                case '+':
                   push(pop() + pop());
                   break;
                case '-':
                   d2 = pop();
                   push(pop() - d2);
                   break;
                case '*':
                   push(pop() * pop());
                   break;
                case '/':
                   d2 = pop();
                   if (d2 != 0.0)
                      push(pop() / d2);
                   else
                      printf("Error: cannot divide by zero!\n");
                   break;
                default:
                   printf("Invalid command\n");
                   break;
            }
        }
        printf("\t%.8g\n", pop());
    }
    return 0;
}