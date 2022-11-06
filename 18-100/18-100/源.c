#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, n;
	scanf("%d %d", &a, &n);
	int sum1 = 0,sum2=0,t;
	for (int i = 0; i < n; i++)
	{
		sum2 = 0,t=1;
		for (int j = 0; j <= i; j++)
		{
			sum2 += a*t;
			t *= 10;
		}
		sum1 += sum2;
	}
	printf("%d", sum1);
}