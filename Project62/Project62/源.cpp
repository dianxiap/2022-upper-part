#define _CRT_SECURE_NO_WARNINGS 1
//状态表示：f[i][j]：表示到（i，j)这个点的所有路径的集合，属性为最大值
//状态计算：将所有到（i，j）点的路径分为从左上来的和从右上来的，状态转移方程为：f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);

#include <iostream>
using namespace std;

const int N = 510, INF = 1e9;

int a[N][N];
int f[N][N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)  //考虑到是从左上和右上两边来的，应该将边界扩大一格
            f[i][j] = -INF;
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
    int res = -INF;
    for (int i = 1; i <= n; i++)res = max(res, f[n][i]);
    cout << res;
}