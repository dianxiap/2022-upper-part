#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


int main() {
	srand((unsigned)time(NULL));
	int ret = rand() % 100 + 1;

	int n;
	while (1) {
		scanf("%d", &n);
		if (n < ret){
			printf("too small\n");
		}
		if (n > ret) {
			printf("too big\n");
		}
		if (n == ret) {
			printf("bingo\n");
			break;
		}
	}
}