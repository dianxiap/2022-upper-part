#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char c,b;
	scanf("%c", &c);
	getchar();
	if (c == 'M')printf("һ");
	else if (c == 'T')
	{
		b = getchar();
		if (b == 'u')printf("��");
		else if (b == 'h')printf("��");
	}
	else if (c == 'W')printf("��");
	else if (c == 'F')printf("��");
	else if (c == 'S') {
		b = getchar();
		if (b == 't')printf("��");
		else if (b == 'u')printf("��");
	}
}