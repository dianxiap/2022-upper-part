#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char fun(char* a)
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (*(a + 1) >= '0' && *(a + i) <= '4')
			*(a + i) += 5;
		if (*(a + i) >= '5' && *(a + i) <= '9')
			*(a + i) -= 5;
	}
	return *a;
}
int main()
{
	char a[100], b[100];
	gets(a);
	gets(b);
	printf("%s\n%s", fun(a), fun(b));
	return 0;
}