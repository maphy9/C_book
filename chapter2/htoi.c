#include <stdio.h>

int htoi(char* str);

int main() {
	char str[10];
	scanf("%s", str);
	int result = htoi(str);
	printf("%d\n", result);

	return 0;
}

int is_digit(char c) {
	return c >= '0' && c <= '9';
}

char to_lower(char c) {
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	return c;
}

int htoi(char* str) {
	int i = 0;
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X')) {
		i = 2;
	}

	int result = 0;
	while (*(str + i) != '\0') {
		if (is_digit(*(str + i))) {
			result *= 16;
			result += *(str + i) - '0';
		} else {
			char c = to_lower(*(str + i));
			if (c >= 'a' && c <= 'f') {
				result *= 16;
				result += c - 'a' + 10;
			} else 
				break;
		}

		i += 1;
	}

	return result;
}
