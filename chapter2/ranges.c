#include <stdio.h>

int main() {
	unsigned char c = -1;
	printf("CHAR: %d - %d\n", -1 * (char) (c / 2) - 1, (char) (c / 2));
	unsigned int i = -1;
	printf("INT: %d - %d\n", -1 * (int) (i / 2) - 1, (int) (i / 2));
	unsigned short s = -1;
	printf("SHORT: %hd - %hd\n", -1 * (short) (s / 2) - 1, (short) (s / 2));

	return 0;
}
