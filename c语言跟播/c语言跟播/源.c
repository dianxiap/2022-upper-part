#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int p(int n) {
	int sum=0;
	sum = sum += n % 10;
	if (n == 0)return sum;
	return sum = p(n / 10) + sum;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d",p(n));
}