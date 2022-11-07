#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void jiwei(int n)
{
	int m = n;
	int count = 0;
	while (n > 0)
	{
		n=n / 10;
		count++;
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%d", m % 10);
		m /= 10;
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	jiwei(n);

}