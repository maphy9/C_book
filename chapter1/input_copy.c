#include <stdio.h>

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(' ');
			while ((c = getchar()) == ' ');
			if (c == EOF)
				break;
		}
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == 'b') {
			putchar('\\');
			putchar('b');
		} else 
			putchar(c);
	}
	return 0;
}
