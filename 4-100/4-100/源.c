#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int n, y, r,sum;
	printf("请输入年月日\n");
	scanf("%d,%d,%d", &n, &y, &r);
	switch (y)
	{
	case 1:sum = 0; break;
	case 2:sum = 31; break;
	case 3:sum = 59; break;
	case 4:sum = 90; break;
	case 5:sum = 120; break;
	case 6:sum = 151; break;
	case 7:sum = 181; break;
	case 8:sum = 212; break;
	case 9:sum = 243; break;
	case 10:sum = 273; break;
	case 11:sum = 304; break;
	case 12:sum = 334; break;
	default:printf("error"); break;
	}
	sum += r;
	int leap;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		leap = 1;
	}
	else
	{
		leap = 0;
	}
	if (leap == 1 && y > 2)
	{
		sum++;
	}
	printf("这是这一年的第%d天", sum);
	return 0;
	
}