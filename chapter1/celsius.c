#include <stdio.h>

#define MAX	300
#define MIN	0
#define STEP	20

int main() {
	printf("Celsius\tFahrenheit\n");
	for (float celsius = MAX; celsius >= MIN; celsius -= STEP)
		printf("%7.0f\t%10.0f\n", celsius, 1.8f * celsius + 32);

	return 0;
}
