#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);

	int i = 0;
	//ż��λ
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	//����λ
	for (i = 32; i >= 1; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	return 0;
}