#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int n, m;
int res;                  // res 存答案

void dfs(int x, int y)    // 爆搜函数
{
    if (x == n && y == m) // 如果搜到了点 (n, m), 那么 res ++ 并返回
    {
        res++;
    }
    if (x < n) dfs(x + 1, y); // 如果不是最下面的点，那么搜该点下面的点
    if (y < m) dfs(x, y + 1); // 如果不是最右边的点，那么搜该点右边的点
}

int main()
{
    scanf("%d %d", &n, &m);
    dfs(0, 0);            // 从点 (0, 0) 开始爆搜
    printf("%d\n", res);
    return 0;
}
