#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 61

int main() {
	char c[N][N];
	int i,j;
	for (i = 0; i < 30; i++) {
		getchar();
		for (j = 0; j < 60; j++){
			c[i][j] = getchar();
		}
	}
	int count = 0;
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 60; j++) {
			if (i > 0 && j > 0 && i < 29 && j < 59) {
				if (c[i][j] < c[i + 1][j] && c[i][j] < c[i - 1][j] && c[i][j] < c[i][j + 1] && c[i][j] < c[i][j - 1]) {
					count++;
				}
			}
		}
	}
	printf("%d", count);

}
