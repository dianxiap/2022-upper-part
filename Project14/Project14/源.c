#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[] = "abc";
	char arr2[] = { 'a','b','c' };
	char arr3[3] = { 'a','b','c' };
	char arr4[4] = "abc";
	printf("%d\n", sizeof(arr1));
	printf("%d\n", sizeof(arr2));
	printf("%d\n", sizeof(arr3));
	printf("%d\n", sizeof(arr4));
	printf("%d\n", strlen(arr1));
	printf("%d\n", strlen(arr2));
	printf("%d\n", strlen(arr3));
	printf("%d\n", strlen(arr4));

}