#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverse_string(char* string) {
	if (*string) {
		reverse_string(string + 1);
		printf("%c", *string);
	}
}
int main() {
	char str[] = "abcdef";
	reverse_string(str);
	printf("\n");
	int i = 0;
	for (i = 0; i < 6; i++) {
		printf("%c ", str[i]);
	}
	return 0;
}
