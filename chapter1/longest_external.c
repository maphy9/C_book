#include <stdio.h>

#define MAX	1000

int max;
char line[MAX + 1];
char longest[MAX + 1];

int get_line();
void copy();

int main() {
	int len;

	while ((len = get_line()) != 0) {
		if (len > max) {
			copy();
			max = len;
		}
	}

	if (max != 0)
		printf("%s\n", longest);


	return 0;
}

int get_line() {
	int length = 0;
	char c;
	while ((c = getchar()) != '\n') {
		if (length == MAX)
			break;

		*(line + length) = c;
		length++;
	}

	if (length == MAX && c != '\n')
		while(getchar() != '\n');
	*(line + length) = '\0';

	return length;
}

void copy() {
	int i = 0;
	while (*(line + i) != '\0') {
		*(longest + i) = *(line + i);
		i++;
	}

	*(longest + i) = '\0';
}

