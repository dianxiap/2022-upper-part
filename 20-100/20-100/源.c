#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double n;
	int m;
	double len=0;
	scanf("%lf %d", &n, &m);
	len = n;
	if (m == 0)printf("%f", len);
	else {
		for (int i = 0; i < m; i++)
		{
			len += n;
			n /= 2;
		}
		printf("%f %f", len,n);
	}
}