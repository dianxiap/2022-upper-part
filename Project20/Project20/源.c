#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 0x11223344;

	char* pa = (char*)&a;

	for (int i = 0; i < 4; i++)
	{	
		*pa = 1;
		pa++;
	}
	printf("%d", a);

}