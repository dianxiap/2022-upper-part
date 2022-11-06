#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int x1,x2=1;
	for (int i=0;i<9;i++)
	{
		x1 = (x2 + 1) * 2;
		x2 = x1;
	}
	printf("%d", x1);
}