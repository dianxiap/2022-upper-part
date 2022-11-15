#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[10][10];
	int N, M;
	scanf("%d %d", &N, &M);
	int sum = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > 0)
			{
				sum += arr[i][j];
			}
		}
	}
	printf("%d", sum);
}