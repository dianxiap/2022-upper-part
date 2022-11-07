#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n;

	scanf("%d", &n);
	int m = n;
	int count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	int p[100];
	for (int i = 0; i < count; i++)
	{
		p[i] = m % 10;
		m /= 10;
	}
	int flag = 1;
	for (int j = 0; j < count; j++)
	{
		if (p[j] != p[count - j - 1]) {
			flag = 0;
		}
	}
	if (flag)printf("是回文", n);
	else printf("不是");
}