#define _CRT_SECURE_NO_WARNINGS 1
//负权边--bellman_ford算法：
//1.遍历k条边（题给定）、
//2.更新所有边的最短距离

#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 10010;

struct Edge
{
    int a;
    int b;
    int w;
}e[M];  //记录点和边权

int n, m, k;
int dist[N];  //距离
int backup[N];  //距离的备份

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)  //循环k次
    {
        memcpy(backup, dist, sizeof dist);  //备份距离，使每次循环只更新一个点的距离
        for (int j = 0; j < m; j++)
        {
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = { a,b,w };
    }
    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2)puts("impossible");  //dist[n]可能被上一个点更新过，可能不是无穷大
    else cout << dist[n];

}


