//有向图的拓扑排序
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;

int n, m;  //点数，边数
int d[N]; //所有点的入度
int h[N], e[N], ne[N], idx;
int q[N]; //数组模拟队列

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;//初始化队列
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])q[++tt] = i; //入度为零的点先入队
    }
    while (hh <= tt)
    {
        int t = q[hh++]; //取队头
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--; //删除上一个点i指向该点j的边
            if (d[j] == 0)q[++tt] = j;
        }
    }
    return tt == n - 1; //n个点都入队了，则为拓扑序
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    //点a,b间建立有向边
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;  //记录每个点的入读
    }
    if (topsort())
    {
        for (int i = 0; i < n; i++)cout << q[i] << ' ';
        cout << endl;
    }
    else cout << "-1";
}