#include <stdio.h>

int any(char* target, char* str);

int main() {
	char target[] = "Hello, world\n";
	printf("%d\n", any(target, "x"));

	return 0;
}

int in(char c, char* str) {
	int i = 0;
	while (*(str + i) != '\0') {
		if (*(str + i) == c)
			return 1;
		i++;
	}

	return 0;
}

int any(char* target, char* str) {
	int i = 0;
	while (*(target + i) != '\0') {
		if (in(*(target + i), str))
			return i;
		i++;
	}

	return -1;
}
