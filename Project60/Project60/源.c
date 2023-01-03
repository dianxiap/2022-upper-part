#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 3;
	printf("%d\n", (a += a -= a * a));
	return 0;
}