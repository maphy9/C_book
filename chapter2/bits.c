#include <stdio.h>

#define MAX_N	64

void print_bin(int x);
int setbits(int x, int p, int n, int y);
int inverse(int x, int p, int n);
int rightrot(int x, int n);

int main() {
	int x = 1321;
	print_bin(x);
	print_bin(rightrot(x, 5));

	return 0;
}

int setbits(int x, int p, int n, int y) {
	int ey = y & ~(~0 << n);
	int ex = x & ~(~0 << (p - n + 1));
	int result = x >> (p + 1);
	result = result << n;
	result = result | ey;
	result = result << (p - n + 1);
	result = result | ex;

	return result;
}

void print_bin(int x) {
	if (x == 0) {
		putchar('0');
		return;
	}

	char bin[100];
	int i = 0;
	while (x != 0) {
		*(bin + i) = '0' + (x % 2);
		x /= 2;
		i++;
	}

	while (i > 0) {
		putchar(*(bin + i - 1));
		i--;
	}
	putchar('\n');
}

int inverse(int x, int p, int n) {
	int ex = x & ~(~0 << (p - n + 1));
	x >>= (p - n + 1);
	int part = x & ~(~0 << n);
	part = ~part & ~(~0 << n);
	x >>= n;
	int result = x << n;
	result = result | part;
	result = result << (p - n + 1);
	result = result | ex;

	return result;
}

int rightrot(int x, int n) {
	if (n > MAX_N)
		return 0;
	int last = x & ~(~0 << n);
	x >>= n;
	char bin[MAX_N];
	for (int i = 0; i < n; i++) {
		int bit = last % 2;
		x <<= 1;
		x |= bit;
		last /= 2;
	}

	return x;
}
