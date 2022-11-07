#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char s[100];
	char c;
	scanf("%s\n", s);
	scanf("%c", &c);
	int len = strlen(s);
	char p[100];
	int i,j=0;
	for (i = 0; i < len; i++)
	{
		while (s[i] == c)
		{
			i++;
		}
		p[j++] = s[i];
	}
	p[j] = '\0';
	printf("%s", p);
}