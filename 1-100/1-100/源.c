#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int count=0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				if (i != j && j != k && i!= k) {
					printf("%d%d%d", i, j, k);
					count++;
					printf("\n");
				}
			}
		}
	}
	printf("%d", count);
}