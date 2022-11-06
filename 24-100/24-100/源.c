#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i;
	double fenmu = 1, fenzi = 2;
	double n,sum=0;
	for (i = 0; i < 20; i++)
	{
		n = fenzi / fenmu;
		sum += n;
		int t = fenzi;
		fenzi = fenmu + fenzi;
		fenmu = t;
	}
	printf("%f", sum);
}