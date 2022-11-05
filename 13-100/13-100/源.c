#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i,j,m,n;
	for (i = 100; i <= 999; i++)
	{
		j = i % 10;
		m = i / 10 % 10;
		n = i / 100;
		if (j * j * j + m * m * m + n * n * n == i)
		{
			printf("%d\n", i);
		}
	}


}