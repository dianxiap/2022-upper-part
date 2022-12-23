#define _CRT_SECURE_NO_WARNINGS 1
//floyd--求多源最短路径
//三重循环，邻接矩阵存储边权
#include <iostream>
#include <cstring> 
using namespace std;

const int N = 210, INF = 1e9;

int n, m, k;
int d[N][N];

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);  //更新最短距离
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)d[i][j] = 0;  //到自身的距离为0,去自环
            else d[i][j] = INF;
        }
    }

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);  //去重边
    }

    floyd();
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (d[a][b] > INF / 2)cout << "impossible" << endl;
        else cout << d[a][b] << endl;
    }
}
