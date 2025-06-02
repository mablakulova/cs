#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN   1000
#define MAXLINES 5000

char *lineptr[MAXLINES];

int _getline(char *s, int n);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int lines);
void swap(char *v[], int i, int j);
void _qsort(char *v[], int left, int right);

int _getline(char *s, int n) {
    int cnt;
    char c;

    cnt = 0;
    while ((c = getchar()) != EOF && c != '\n' && cnt < n-1) {
        *s++ = c;
        cnt++;
    }
    if (c == '\n') {
        *s++ = c;
        cnt++;
    }
    
    *s = '\0';
    return cnt;
}

int readlines(char *lineptr[], int maxlines) {
    int buflen, lines;
    char *p, bufline[MAXLEN];
    
    lines = 0;
    while ((buflen = _getline(bufline, MAXLEN)) > 0) {
        if (lines < maxlines && (p = malloc(buflen)) != NULL) {
            bufline[buflen-1] = '\0';
            strcpy(p, bufline);
            lineptr[lines++] = p;
        }
        else {
            return -1;
        }
    }
    return lines;
}

void writelines(char *lineptr[], int lines) {
    int i;

    for (i = 0; i < lines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

void swap(char *v[], int i, int j) {
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void _qsort(char *v[], int left, int right) {
    int i, last;
    if (left >= right)
       return;
    swap(v, left, (left + right)/2);

    last = left;
    for (i = left+1; i <= right; i++)
       if(strcmp(v[i], v[left]) < 0)
          swap(v, ++last, i);
    swap(v, left, last);
    _qsort(v, left, last-1);
    _qsort(v, last+1, right);
}

int main(void) {
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        _qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Error: input too big!\n");
        return 1;
    }
}