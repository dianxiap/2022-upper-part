#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

long long p(int n)
{
	long long i = 1;
	for (int j = 1; j <= n; j++)
	{
		i *= j;
	}
	return i;
}

int main()
{
	int i;
	long long sum = 0;
	for (i = 1; i <= 20; i++)
	{
		sum += p(i);
	}
	printf("%lld", sum);

}