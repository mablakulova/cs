#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

int main(void) {
	char *s, *w_ar[MAX_LEN], *w_buf;
	s = malloc(MAX_LEN * sizeof(char));
	scanf("%[^\n]", s);

	int i, w_in, w_cnt;
	for (i = 0; i < MAX_LEN; i++)
		w_ar[i] = malloc(MAX_LEN * sizeof(char));

    w_buf = malloc(MAX_LEN * sizeof(char));
	w_in = 0, w_cnt = 0;

	while (*s) {
		if (isspace(*s)) {
			*w_buf++ = '\0';
			w_in = 0;
			w_cnt++;
		} else {
			if (!w_in)
				w_ar[w_cnt] = w_buf;
			*w_buf++ = *s;
			w_in = 1;
		}
		s++;
	}
	*w_buf++ = '\0';
	w_cnt++;

	for (i = 0; i < w_cnt; i++) {
		printf("%s\n", w_ar[i]);
	}
	return 0;
}