#include <stdio.h>

#define IN	1
#define OUT	0
#define LENGTH	10
#define CHAR_LENGTH	26

int main() {
	int c, nw, i;
	i = nw = 0;
	int state = OUT;
	int histogram_words[LENGTH] = {0};
	int histogram_characters[CHAR_LENGTH] = {0};

	while ((c = getchar()) != EOF) {
		if (state == IN && (c == '\n' || c == ' ' || c == '\t')) {
			state = OUT;
			i += 1;
		} else if (!(c == '\n' || c == ' ' || c == '\t')) {
			if (c >= 'a' && c <= 'z')
				*(histogram_characters + c - 'a') += 1;
			else if (c >= 'A' && c <= 'Z')
				*(histogram_characters + c - 'A') += 1;

			state = IN;
			if (i < LENGTH)
				*(histogram_words + i) += 1;
		}
	}

	for (int j = 0; j < i; j++) {
		printf("%d) ", j + 1);
		for (int k = 0; k < *(histogram_words + j); k++)
			printf("-");
		printf("\n");
	}

	for (int j = 0; j < CHAR_LENGTH; j++) {
		printf("%c: ", 'a' + j);
		for (int k = 0; k < *(histogram_characters + j); k++)
			printf("-");
		printf("\n");
	}

	return 0;
}

