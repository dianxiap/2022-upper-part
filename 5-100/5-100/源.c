#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int x, y, z;
	printf("输入三个整数：");
	scanf("%d%d%d", &x, &y, &z);
	if (x > y)
	{
		int t = x;
		x = y;
		y = t;
	}
	if (x > z)
	{
		int s = x;
		x = z;
		z = s;
	}
	if (y > z)
	{
		int p = y;
		y = z;
		z = p;
	}

	printf("%d %d %d", x, y, z);
}