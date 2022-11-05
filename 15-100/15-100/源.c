#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	n >= 90 ? printf("A") : n >= 60 && n <= 89 ? printf("B") : printf("C");
}