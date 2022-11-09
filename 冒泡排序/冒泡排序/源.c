#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void bubble(int* arr, int sz)
{
	for (int i = 0; i < sz-1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}
int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sz);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}