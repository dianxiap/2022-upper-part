#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n;
	int i;
	for (i = 2;i <= 1000;i++)
	{
		int sum = 0;
		for (int j = 1;j < i;j++)
		{
			if (i % j == 0)
			{
				sum += j;
			}
		}
		if (sum == i)
			printf("%d\n", i);
	}
}