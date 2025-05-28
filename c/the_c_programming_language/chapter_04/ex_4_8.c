#include <stdio.h>

char buf = '\0';

int getch(void);
void ungetch(int c);

int getch(void) {
    int c;
    
    if (buf != '\0') 
       c = buf;
    else
       c = getchar();
    
    buf = '\0';
    return c;
}

void ungetch(int c) {
    if (buf == '\0')
       buf = c;
    else
       printf("Error: character buffer is full\n");
}

int main(void) {
    ungetch('a');
    printf("%c\n", getch());

    ungetch('x');
    ungetch('y'); 
    return 0;
}