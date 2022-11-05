#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int x,m,n;
	int i,j;
	for (i = 2; i <= 168; i += 2)
	{
		for (j = 2; j <= 168; j+=2) {
			if (i* j == 168) {
				m = (i + j) / 2;
				n = (i - j) / 2;
				x = n * n - 100;
				printf("%d\n", x);
			}
		}
	}
}