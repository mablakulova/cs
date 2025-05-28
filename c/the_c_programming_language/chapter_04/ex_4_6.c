#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_COUNT   100
#define BUF_SIZE    100
#define MAX_OP      100
#define NUMBER      '0'
#define MATH_FUNC   'F'

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
        if ((c == '-' || c == '+') && isdigit(c = getch())) {
            s[++i] = c;
        } else if (c == 's' && (s[++i] = c = getch()) == 'i' && (s[++i] = c = getch()) == 'n') {
            s[++i] = '\0';
            return MATH_FUNC;
        } else if (c == 'e' && (s[++i] = c = getch()) == 'x' && (s[++i] = c = getch()) == 'p') {
            s[++i] = '\0';
            return MATH_FUNC;
        } else if (c == 'p' && (s[++i] = c = getch()) == 'o' && (s[++i] = c = getch()) == 'w') {
            s[++i] = '\0';
            return MATH_FUNC;
        } else {
            if (c != s[0])
               ungetch(c);
            s[1] = '\0';
            return s[0];
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
    double op1, op2, last_v;
    char s[MAX_OP], v;
    double l[26];

    for (int i = 0; i < 26; i++)
       l[i] = 0.0;

    while ((type = get_op(s)) != EOF) {
        switch (type) {
            case NUMBER:
               push(atof(s));
               break;
            case MATH_FUNC:
               if (strcmp(s, "sin") == 0)
                  push(sin(pop()));
               else if (strcmp(s, "exp") == 0)
                  push(exp(pop()));
               else if (strcmp(s, "pow") == 0) {
                  op2 = pop();
                  push(pow(pop(), op2));
               } else 
                  printf("Error: Invalid math funtion %s\n", s);
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
            case '?':
               op2 = pop();
               printf("The peek element: %.8g\n", op2);
               push(op2);
               break;
            case '#':
               op2 = pop();
               push(op2);
               push(op2);
               break;
            case '~':
               op2 = pop();
               op1 = pop();
               push(op2);
               push(op1);
               break;
            case '!':
               clear();
               break;
            case '$': /* last printed value */
               push(last_v);
               break;
            case '=':
               if (v >= 'a' && v <= 'z') {
                  pop();
                  l[v - 'a'] = pop();
               } else {
                  printf("Error: Invalid variable for %c\n", type);
               }
               break;
            case '\n':
               last_v = pop();
               printf("\t%.8g\n", last_v);
               break;
            default:
               if (type >= 'a' && type <= 'z')
                  push(l[type - 'a']); 
               else 
                  printf("Invalid command\n");
               break;
        }
        v = type;
    }
    return 0;
}