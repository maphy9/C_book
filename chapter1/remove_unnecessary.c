#include <stdio.h>

#define MAX	1000

int get_line(char* str, int max);
void move(char* str, int len, int n);
int remove_trailing_spaces(char* str, int len);

int main() {
	int len;
	char str[MAX + 1];

	while ((len = get_line(str, MAX)) != 0) {
		remove_trailing_spaces(str, len);
		printf("%s *\n", str);
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

void move(char* str, int len, int n) {
	int i = 0;
	while (i + n < len) {
		*(str + i) = *(str + i + n);
		i++;
	}
	*(str + i) = '\0';
}

int remove_trailing_spaces(char* str, int len) {
	int i = len - 1;
	while (i >= 0 && (*(str + i) == ' ' || *(str + i) == '\t'))
		i--;
	*(str + i + 1) = '\0';

	int n = 0;
	while (*(str + n) == ' ' || *(str + n) == '\t')
		n++;
	move(str, i + 1, n);

	return i + 1;
}
