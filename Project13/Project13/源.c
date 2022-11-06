#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void init(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void reverse(int a[], int n)
{
	int temp = 0;
	int* left = a;
	int* right = a + n - 1;
	while (left < right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}

}
int main()
{
	int a[10];
	init(a, 10);
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	reverse(a, 10);
	print(a, 10);
}