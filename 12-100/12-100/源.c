#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n=1;
	for (int i = 101; i <= 200; i++) {
		n = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0)
			{
				n = 0;
			}
		}
		if (n)printf("%d\n", i);
	}
}