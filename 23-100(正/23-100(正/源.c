#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i, j, k;
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= 3 - i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= i * 2; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i<=3; i++)
	{
		for (j = 0; j <= i+1; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= (2 - i) * 2; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}