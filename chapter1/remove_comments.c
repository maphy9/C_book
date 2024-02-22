#include <stdio.h>

#define MAX	1000

int get_code(char* code, int max);
void move(char* str, int len, int n);

int main() {
	char code[MAX + 1];
	int len = get_code(code, MAX);
	int is_quote = 0;

	int i = 0;
	while (i < len) {
		if (is_quote) {
			if (*(code + i) == '"')
				is_quote = 0;
			i++;
			continue;
		}

		if (*(code + i) == '/' && *(code + i + 1) == '/') {
			int n = 2;
			while (i + n < len && *(code + i + n) != '\n')
				n++;
			move(code + i, len, n);
			len -= n;
		} else if (*(code + i) == '/' && *(code + i + 1) == '*') {
			int n = 2;
			while (i + n < len && (*(code + i + n) != '/' || *(code + i + n - 1) != '*'))
				n++;
			move(code + i, len, n + 1);
			len -= n;
		} else {
			if (*(code + i) == '"')
				is_quote = 1;
			i++;
		}
	}

	printf("%s\n", code);

	return 0;
}

int get_code(char* code, int max) {
	int len = 0;
	int c;
	while((c = getchar()) != EOF) {
		if (len == max)
			break;
		*(code + len) = c;
		len++;
	}
	if (len == max && c != EOF)
		while(getchar() != EOF);
	*(code + len) = '\0';

	return len;
}

void move(char* str, int len, int n) {
	int i = 0;
	while (i + n < len) {
		*(str + i) = *(str + i + n);
		i++;
	}
	*(str + i) = '\0';
}
