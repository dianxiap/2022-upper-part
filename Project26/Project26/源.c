#include <stdio.h>

int tem[100];

void p(int q[],int l,int r)
{
	if (l >= r)return;
	int k = 0;
	for(int i=l;i<=r;i++)
	{
		if (q[i] % 2 == 1)tem[k++] = q[i];
	}
	for (int i = l; i <= r; i++)
	{
		if (q[i] % 2 == 0)tem[k++] = q[i];
	}
	for (int i = l, j = 0; i <= r; i++)q[i] = tem[j++];
}

int main()
{
	int a[100];
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)scanf_s("%d", &a[i]);
	p(a, 0, n - 1);
	for (int i = 0; i < n; i++)printf("%d ", a[i]);
}