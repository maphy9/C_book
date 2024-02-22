#include <stdio.h>

int main() {
	int c;
	long cc = 0;
	long cs = 0;
	while ((c = getchar()) != EOF) {
		cc++;
		if (c == ' ' || c == '\t' || c == '\n')
			cs++;
	}

	return 0;
}
