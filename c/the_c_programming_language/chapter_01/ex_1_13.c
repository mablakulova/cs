#include <stdio.h>

#define IN   1
#define OUT  0
#define MAX_WORDS  1000

/* 
 * Exercise 1-13. Write a program to print a histogram of the lengths of words in 
 * its input. It is easy to draw the histogram with the bars horizontal; a vertical 
 * orientation is more challenging. 
 */
int main()  {
    long c, i, word_length, word_count, state;
    int wordarr[MAX_WORDS];
    
    for (i = 0; i < MAX_WORDS; ++i)
       wordarr[i] = 0;
    
    state = OUT; word_length = word_count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            if (state) {
                wordarr[word_count++] = word_length;
                word_length = 0;
            }
            state = OUT;
        } else {
            state = IN;
            ++word_length;
        }
    }

    for (i = 0; i < word_count; ++i)
       printf("The length of the %ld th word is %d\n", i + 1, wordarr[i]);
    return 0;
}