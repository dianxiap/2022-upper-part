#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void reverse(char a[], int n)
//{
//	if (n >= 1)
//	{
//		printf("%c ", a[n - 1]);
//		reverse(a, n - 1);
//	}
//}
//
//int main()
//{
//	char *a="hello";
//	reverse(a, 5);
//
//}
void fun(char *a, int n)
{
	if (n >= 1)
	{
		printf("%c ", a[n - 1]);
		fun(a, n - 1);
	}
}


int main()
{
	char s[5];
	scanf("%s", s);
	int len = sizeof(s) / sizeof(s[0]);
	fun(s, 6);
}