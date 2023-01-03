#define _CRT_SECURE_NO_WARNINGS 1
//01背包问题：
//1.每个物品只有1个，可以选或不选，求在容量限制下的价值最大值。
//2.f[i][j]表示：在前i种物品中选，并且总体积小于等于j的选法的集合，存的数是每一种选法的总价值的最大值
//3.状态转移方程：f[i][j]=max(f[i-1][j],f[i-1][j-v[i]+w[i])
//4.用一维数组f[j]优化二维f[i][j]
#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)    //逆序更新，保证该次迭代用的是i-1的状态
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << endl;
}
//完全背包问题：
//1.每个物品有无限个，求价值最大是多少。
//2.    状态转移方程：              f[i][j]=max(f[i−1][j],f[i][j−v]+w)   f[i][j]只依赖于该次的规划，
//      01背包问题的状态转移方程    f[i][j]=max(f[i−1][j],f[i−1][j−vi]+wi)  f[i][j]的值依赖于f[i-1]的规划过程，因此要逆序更新，防止第i-1个物品的规划被本轮覆盖
//                  
#include <iostream>
using namespace std;

const int N = 1010;

int v[N], w[N];
int f[N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << endl;

}