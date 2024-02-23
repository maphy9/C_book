#include <stdio.h>

int atoi(char* str);
int is_digit(char c);

int atoi(char* str) {
	int i = 0;
	int result = 0;
	while (*(str + i) != '\0') {
		if (!is_digit(*(str + i)))
			break;
		result *= 10;
		result += *(str + i) - '0';
	}

	return result;
}

int is_digit(char c) {
	return c >= '0' && c <= '9';
}
