#include <stdio.h>

#define MAX	1000

int get_line(char* str, int max);
void copy(char* to, char* from);

int main() {
	int len;
	int max = 0;
	char line[MAX + 1];
	char longest[MAX + 1];

	while ((len = get_line(line, MAX)) != 0) {
		if (len > max) {
			copy(longest, line);
			max = len;
		}
	}

	if (max != 0)
		printf("%s\n", longest);

	return 0;
}

int get_line(char* str, int max) {
	int length = 0;
	char c;
	while ((c = getchar()) != '\n') {
		if (length == max)
			break;

		*(str + length) = c;
		length++;
	}

	if (length == max && c != '\n')
		while(getchar() != '\n');
	*(str + length) = '\0';

	return length;
}

void copy(char* to, char* from) {
	int i = 0;
	while (*(from + i) != '\0') {
		*(to + i) = *(from + i);
		i++;
	}

	*(to + i) = '\0';
}
