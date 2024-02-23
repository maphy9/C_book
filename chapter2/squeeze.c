#include <stdio.h>

void squeeze(char* target, char* str);

int main() {
	char target[] = "Hello, world";
	printf("%s\n", target);
	squeeze(target, "ol");
	printf("%s\n", target);

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

void squeeze(char* target, char* str) {
	int i = 0;
	int j = 0;
	while (*(target + i) != '\0') {
		if (!in(*(target + i), str)) {
			*(target + j) = *(target + i);
			j++;
		}
		i++;
	}
	*(target + j) = '\0';
}
