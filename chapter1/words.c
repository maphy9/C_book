#include <stdio.h>

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			putchar('\n');
			while ((c = getchar()) == ' ' || c == '\n' || c == '\t');
			if (c == EOF)
				break;
		}
		putchar(c);
	}

	return 0;
}
