#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char i, j, k;  //i��a�Ķ��֣�j��B�ģ�k��c��
	for (i = 'x'; i <= 'z'; i++)
	{
		for (j = 'x'; j <= 'z'; j++) {
			if (i != j)
			{
				for (k = 'x'; k <= 'z'; k++)
				{
					if (i != k && j != k)
					{
						if (i != 'x' && k != 'x' && k != 'z')
							printf("a-%c\tb-%c\tc-%c", i, j, k);
					}
				}
			}
		}
	}
}