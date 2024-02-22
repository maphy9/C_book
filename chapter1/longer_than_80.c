#include <stdio.h>

#define MAX	1000

int get_line(char* str, int max);

int main() {
	char str[MAX + 1];
	int len;

	while ((len = get_line(str, MAX)) != 0) {
		if (len > 80)
			printf("%s\n", str);
	}

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

