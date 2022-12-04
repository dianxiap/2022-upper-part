#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double t, c, s;
	double v;
	scanf("%lf%lf%lf", &t, &c, &s);
	v = 1.0*c / t;
	int time=(s - c) / v;
	printf("%d", time);
}
