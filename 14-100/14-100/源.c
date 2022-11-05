#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int isprime(int n)
{
	if (n < 2)return 0;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d=", n);
	for (int i = 2; i <= n; i++)
	{
		if (isprime(i))
		{
			if (n == i)
			{
				printf("%d", i);
				break;
			}
			else if(n%i==0)
			{
				printf("%d*", i);
				n = n / i;
				i = 2;
			}
		}
	}

}