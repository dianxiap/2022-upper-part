#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char c,b;
	scanf("%c", &c);
	getchar();
	if (c == 'M')printf("一");
	else if (c == 'T')
	{
		b = getchar();
		if (b == 'u')printf("二");
		else if (b == 'h')printf("四");
	}
	else if (c == 'W')printf("三");
	else if (c == 'F')printf("五");
	else if (c == 'S') {
		b = getchar();
		if (b == 't')printf("六");
		else if (b == 'u')printf("七");
	}
}