#include <stdio.h>

#define MAX	300
#define MIN	0
#define STEP	20

int main() {
	printf("Fahrenheit\tCelsius\n");
	float celsius;
	float fahr = MIN;
	while (fahr <= MAX) {
		celsius = 5.0 / 9 * (fahr - 32);
		printf("%10.0f\t%7.1f\n", fahr, celsius);
		fahr += STEP;
	}

	return 0;
}
