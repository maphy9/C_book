#include <stdio.h>

#define MAX	1000
#define STACK_SIZE	100

int get_code(char* code, int max);
int is_opening(char c);
int is_closing(char c);
int match(char c);

char stack[STACK_SIZE];
int p_stack = 0;

int main() {
	char code[MAX + 1];
	int len = get_code(code, MAX);
	int is_analyzing = 1;

	int i = 0;
	while (i < len) {
		if (!is_analyzing) {
			if (match(*(code + i)) && (*(code + i) == '"' || *(code + i) == '\'') && *(code + i - 1) != '\\') {
				p_stack--;
				is_analyzing = 1;
			}
			i++;
			continue;
		}

		if (match(*(code + i))) {
			p_stack--;
		} else if (is_opening(*(code + i))) {
			*(stack + p_stack) = *(code + i);
			p_stack++;
			if (*(code + i) == '\'' || *(code + i) == '"')
				is_analyzing = 0;
		} else if (is_closing(*(code + i))) {
			p_stack = STACK_SIZE;
			break;
		}

		if (is_analyzing && *(code + i) == '/' && *(code + i + 1) == '/') {
			i += 2;
			while (i < len && *(code + i) != '\n')
				i++;
		}
		if (is_analyzing && *(code + i) == '/' && *(code + i + 1) == '*') {
			i += 2;
			while (i < len && (*(code + i) != '/' || *(code + i - 1) != '*'))
				i++;
		}
		i++;
	}

	if (p_stack == 0)
		printf("No syntax error found\n");
	else
		printf("Syntax error!!!\n");

	return 0;
}

int get_code(char* code, int max) {
	int len = 0;
	int c;
	while((c = getchar()) != EOF) {
		if (len == max)
			break;
		*(code + len) = c;
		len++;
	}
	if (len == max && c != EOF)
		while(getchar() != EOF);
	*(code + len) = '\0';

	return len;
}

int is_opening(char c) {
	return c == '(' || c == '[' || c == '{' || c == '"' || c == '\'';
}

int is_closing(char c) {
	return c == ')' || c == ']' || c == '}' || c == '"' || c == '\'';
}

int match(char c) {
	if (p_stack == 0)
		return 0;

	char stack_top = *(stack + p_stack - 1);
	switch (stack_top) {
		case '(':
			return c == ')';
		case '[':
			return c == ']';
		case '{':
			return c == '}';
		case '"':
			return c == '"';
		case '\'':
			return c == '\'';
		default:
			return 0;
	}
}
