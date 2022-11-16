#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int f(int n)
{
	int i = 1;
	for (int j = 1; j <= n; j++)
	{
		i = i * j;
	}
	return i;
}
int main()
{
	int n;
	scanf("%d", &n);
	int m=f(n);
	printf("%d", m);
}