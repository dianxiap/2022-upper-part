#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int a = 1, b = 1, c;
	printf("%d\n%d\n", a, b);
	for (int i = 2; i < 40; i++) {
		c = a + b;
		printf("%d\n", c);
		a = b;
		b = c;
	}
}