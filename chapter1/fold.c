#include <stdio.h>

#define MAX	1000
#define MIN_LEN	20
#define MAX_LEN	40

int get_line(char* str, int max);

int main() {
	char str[MAX + 1];
	int len = get_line(str, MAX);

	int i = 0;
	int count = 0;
	while (i < len) {
		if (count >= MIN_LEN && (*(str + i) == ' ' || *(str + i) == '\t')) {
			putchar('\n');
			count = 0;
			while (i < len && (*(str + i) == ' ' || *(str + i) == '\t'))
				i++;
		} else if (count >= MAX_LEN) {
			putchar('\n');
			count = 0;
		}	else {
			putchar(*(str + i));
			i++;
			count++;
		}
	}
	putchar('\n');

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
