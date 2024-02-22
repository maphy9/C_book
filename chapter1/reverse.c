#include <stdio.h>

#define MAX	1000

int get_line(char* str, int max);
void reverse(char* str, int len);

int main() {
	int len;
	char str[MAX + 1];

	while ((len = get_line(str, MAX)) != 0) {
		reverse(str, len);
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

void reverse(char* str, int len) {
	int i = 0;
	int j = len - 1;
	while (i < j) {
		char temp = *(str + i);
		*(str + i) = *(str + j);
		*(str + j) = temp;
		i++;
		j--;
	}
}
