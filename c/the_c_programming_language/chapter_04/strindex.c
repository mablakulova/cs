#include <stdio.h>

#define MAX_LINE 1000

int get_line(char buffer[], int arr_size);
int strindex(char s[], char t[]);

int main() {
    char pattern[] = "ould";
    char current_line[MAX_LINE];
    
    while (get_line(current_line, MAX_LINE) > 0) {
        if (strindex(current_line, pattern) >= 0) {
            printf("%s", current_line);
        }
    }
    return 0;
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

int strindex(char s[], char t[]) {
    int i, j, temp;
    for (i = 0; s[i] != '\0'; i++) {
        for (temp = i, j = 0; s[temp] == t[j] && t[j] != '\0'; temp++, j++)
           ;
        
        if (t[j] == '\0' && j > 0) {
            return i;
        }
    }

    return -1;
}