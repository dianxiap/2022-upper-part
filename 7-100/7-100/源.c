#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int n;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d=%-4d", j, i, i * j);
		}
		printf("\n");
	}
}