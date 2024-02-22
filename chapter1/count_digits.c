#include <stdio.h>

int main() {
	int c, nother, nblank;
	int ndigit[10] = {0};
	nother = nblank = 0;

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			*(ndigit + c - '0') += 1;
		else if (c == ' ' || c == '\n' || c == '\t')
			nblank++;
		else 
			nother++;
	}

	printf("White spaces: %d\n", nblank);
	printf("Other: %d\n", nother);
	for (int i = 0; i < 10; i++)
		printf("%d: %d\n", i, *(ndigit + i));

	return 0;
}
