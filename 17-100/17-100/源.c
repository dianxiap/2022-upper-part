#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char s;
	int yingwen = 0, kongke = 0, shuzi = 0, qita = 0;
	while ((s = getchar()) != '\n')
	{
		if (s == ' ')
		{
			kongke++;
		}
		else if (s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z')
		{
			yingwen++;
		}
		else if (s >= '0' && s <= '9')
		{
			shuzi++;
		}
		else qita++;
	}
	printf("yingwen=%d\n shuzi=%d\n kongke=%d\n qita=%d", yingwen, shuzi, kongke, qita);

}