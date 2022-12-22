#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];  //邻接矩阵，存的是从点N到点N的距离
int dist[N];  //记录每一个点到第一个点的距离
bool st[N];  //记录每个点的最短距离是否确认了

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist); //初始时所有点距离1号点距离无穷大
    dist[1] = 0;  //1号点距离自身距离为0
    for (int i = 1; i <= n; i++)  //循环n次
    {
        //找到当前未确定最短路径的点中距离最短的点
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            //!st[j]判断是否为未确定最短路径的点
            //(dist[t]>dist[j)找出距离最短的点
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;  //表示该点的最短路径确认了
        for (int j = 1; j <= n; j++)
        {
            //用t点把所有点的最短距离重新更新一遍：比较从1号点到j号点 和 从1号点到t号点再到j号点的距离
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);  //初始时1距离为1号点0，其他点距1号点距离无穷大

    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);//有重边则找距离最短的一条边
    }
    cout << dijkstra() << endl;
}

