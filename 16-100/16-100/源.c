#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int m, n;
	scanf("%d,%d", &m, &n);
	int t;
	int p = m, q = n;
	while (n!=0)
	{
		t = m % n;
		m = n;
		n = t;
	}
	int yue = m;
	int bei = p * q / yue;
	printf("%d %d", yue, bei);
}