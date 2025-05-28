#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_COUNT   100
#define BUF_SIZE    100
#define MAX_OP      100
#define NUMBER      '0'

double value_stack[MAX_COUNT];
char buf[BUF_SIZE];
int buf_cnt = 0;
int val_cnt = 0;

void push(double f);
double pop(void);
void clear(void);
int getch(void);
void ungetch(int c);
int get_op(char s[]);

void push(double f) {
    if (val_cnt < MAX_COUNT)
       value_stack[val_cnt++] = f;
    else
       printf("Error: double stack is full\n");
}

double pop(void) {
    if (val_cnt > 0) {
        return value_stack[--val_cnt];
    } else {
       printf("Error: double stack is empty\n");
       return 0.0;
    }
}

void clear(void) {
    val_cnt = 0;
}

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

int get_op(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
       ;
    
    i = 0;
    if (!isdigit(c) && c != '.') {
        if (c == '-' || c == '+') {
            if (isdigit(c = getch())) {
                s[++i] = c;
            } else {
                ungetch(c);
                s[1] = '\0';
                return s[0];
            }
        } else {
            s[1] = '\0';
            return c;
        }
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
           ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
           ;
    }

    s[i] = '\0';
    if (c != EOF)
       ungetch(c);
    return NUMBER;
}

int main(void) {
    int type;
    double op1, op2;
    char s[MAX_OP];

    while ((type = get_op(s)) != EOF) {
        switch (type) {
            case NUMBER:
               push(atof(s));
               break;
            case '+':
               push(pop() + pop());
               break;
            case '-':
               op2 = pop();
               push(pop() - op2);
               break;
            case '*':
               push(pop() * pop());
               break;
            case '/':
               op2 = pop();
               if (op2 != 0.0)
                  push(pop() / op2);
               else
                  printf("Cannot divide by zero\n");
               break;
            case '%':
               op2 = pop();
               if (op2 != 0.0)
                  push(fmod(pop(), op2));
               else
                  printf("Cannot divide by zero\n");
               break;
            case '?': /* print element without popping */
               op2 = pop();
               printf("The peek element: %.8g\n", op2);
               push(op2);
               break;
            case '#': /* duplicate element */
               op2 = pop();
               push(op2);
               push(op2);
               break;
            case '~': /* swap top elements */
               op2 = pop();
               op1 = pop();
               push(op2);
               push(op1);
               break;
            case '!': /* clear stack */
               clear();
               break;
            case '\n':
               printf("\t%.8g\n", pop());
               break;
            default:
               printf("Invalid command\n");
               break;
        }
    }
    return 0;
}