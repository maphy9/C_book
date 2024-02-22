#include <stdio.h>

#define MAX	1000
#define TAB_SIZE	2

int get_line(char* str, int max);
int replace_tabs(char* str, int len);
int replace_spaces(char *str, int len);
void l_move(char* str, int len, int n);
void r_move(char* str, int len, int n);

int main() {
	char line[MAX + 1];
	int len = get_line(line, MAX);
	len = replace_tabs(line, len);
	printf("%s\n", line);
	len = replace_spaces(line, len);
	printf("%s\n", line);

	return 0;
}

int get_line(char* str, int max) {
	int length = 0;
	char c;
	while ((c = getchar()) != '\n') {
		if (length == max)
			break;

		*(str + length) = c;
		length++;
	}

	if (length == max && c != '\n')
		while(getchar() != '\n');
	*(str + length) = '\0';

	return length;
}

int replace_tabs(char* str, int len) {
	int i = 0;
	while (*(str + i) != '\0') {
		if (*(str + i) == '\t') {
			l_move(str + i, len - i, TAB_SIZE - 1);
			len += TAB_SIZE - 1;
			for (int j = 0; j < TAB_SIZE; j++)
				*(str + i + j) = ' ';
		}

		i++;
	}
	return len;
}

int replace_spaces(char *str, int len) {
	int i = 0;
	while (*(str + i + TAB_SIZE) != '\0') {
		int j = 0;
		while (*(str + i + j) == ' ')
			j++;

		if (j == TAB_SIZE) {
			*(str + i) = '\t';
			r_move(str + i + 1, len - i - 1, TAB_SIZE - 1);
			len -= TAB_SIZE - 1;
		}

		i++;
	}

	return len;
}

void l_move(char* str, int len, int n) {
	int i = len + n;
	while (i >= n) {
		*(str + i) = *(str + i - n);
		i--;
	}
}


void r_move(char* str, int len, int n) {
	int i = 0;
	while (i + n < len) {
		*(str + i) = *(str + i + n);
		i++;
	}
	*(str + i) = '\0';
}
