#include<stdio.h>
#define M 100000000
char q[M]; ? ? ? ? ? ? //A串
int n0[M], n1[M], n2[M];
int divide(int n, int* q, int l, int r);//二分查找
int main()
{
	char son[4]; ? ? ? ? ? ? //B串（子串）
	int i = 0;
	while ((q[i] = getchar()) != '\n')i++;
	scanf("%s", son);
	int c1 = 0, c2 = 0, c3 = 0;
	for (int j = 0; j < i; j++)//将三个字母出现的坐标分别装进三个数组（假设为abc）
	{
		if (q[j] == son[0]) n0[c1++] = j;//所有a坐标的集合
		if (q[j] == son[1]) n1[c2++] = j;//所有b坐标的集合
		if (q[j] == son[2]) n2[c3++] = j;//所有c坐标的集合
	}
	int result = 0, r1 = 0, r1_ = c2, r2 = 0, add = 0;
	for (int k = c1 - 1; k >= 0; k--) //从后往前找，节约的是找b的循环
	{//该循环找位于最后一个a前面的第一个b（本质上是在b的坐标集合中找到第一次出现的比a坐标大的值并赋值给r1）
		r1 = divide(n0[k], n1, 0, c2 - 1);
		for (int h = r1; h < r1_; h++)//该循环才是主要被优化的循环，其他的似乎没有什么太大区别
		{//c集合中找第一个比b大的c的出现位置
			r2 = divide(n1[h], n2, 0, c3 - 1);//r2为比当前b小的第一个c在c坐标集合中的序号数
			add %= 10007;
			if (n1[h] < n2[r2])add += (c3 - r2);//由于c已经是最后一个字母，找到第一个满足条件的c意味着此后所有的c都满足条件，直接累加就行
			? ? ? ? ? ? /*add不用清零，因为这一个小循环结束所能累加的仅仅是当前b到上一个a区间内的所有b的子串数量，add需要保留上一个循环的累
			? ? ? ? ? ? 加值才能保证在循环结束时（第32行）为当前a的子串数量*/
		}
		r1_ = r1;//备份目前循环b的位置，作为下一次循环的结束位置
		result += add;
		result %= 10007;
	}
	printf("%d", result);
	return 0;
}
int divide(int n, int* q, int l, int r)
{
	int mid = l + r >> 1;
	while (l < r)
	{
		if (n > q[mid])l = mid + 1;
		else r = mid;
		mid = l + r >> 1;
	}
	return mid;
}