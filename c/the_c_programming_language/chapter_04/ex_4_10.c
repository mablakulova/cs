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
int val_cnt = 0;
int buf_p = 0;

void push(double f);
double pop(void);
void clear(void);
int get_line(char buffer[], int arr_size);
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

int get_line(char buffer[], int arr_size) {
    int c, cnt;
    for (cnt = 0; cnt < arr_size - 1 && (c = getchar()) != EOF && c != '\n'; cnt++) {
        buffer[cnt] = c;
    }

    if (c == '\n') {
        buffer[cnt++] = c;
    }

    buffer[cnt] = '\0';
    return cnt;
}

int get_op(char s[]) {
    if (buf[buf_p] == '\0') {
        get_line(buf, BUF_SIZE);
        buf_p = 0;
    }

    int i, c;
    while ((s[0] = c = buf[buf_p++]) == ' ' || c == '\t')
       ;
    
    i = 0;
    if (!isdigit(c) && c != '.') {
        if ((c == '-' || c == '+') && isdigit(c = buf[buf_p++])) {
            s[++i] = c;
        } else if (c == 's' && (s[++i] = c = buf[buf_p++]) == 'i' && (s[++i] = c = buf[buf_p++]) == 'n') {
            s[++i] = '\0';
            return MATH_FUNC;
        } else if (c == 'e' && (s[++i] = c = buf[buf_p++]) == 'x' && (s[++i] = c = buf[buf_p++]) == 'p') {
            s[++i] = '\0';
            return MATH_FUNC;
        } else if (c == 'p' && (s[++i] = c = buf[buf_p++]) == 'o' && (s[++i] = c = buf[buf_p++]) == 'w') {
            s[++i] = '\0';
            return MATH_FUNC;
        } else {
            if (c != s[0])
               buf[--buf_p] = c;
            s[1] = '\0';
            return s[0];
        }
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = buf[buf_p++]))
           ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = buf[buf_p++]))
           ;
    }

    s[i] = '\0';
    if (c != EOF)
       buf[--buf_p] = c;
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