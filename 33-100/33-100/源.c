#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int flag = 1;
	if (n < 2)flag = 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
		{
			flag = 0;
		}
	}
	if (flag)printf("ËØÊý");
	else printf("²»ÊÇ");
}