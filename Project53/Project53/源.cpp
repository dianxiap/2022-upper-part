#define _CRT_SECURE_NO_WARNINGS 1
//prim算法，主体思路与dijkstra算法思路相同：
//1.初始化正无穷
//2.求出不在集合中的距离集合最近的点
//3.用该点更新其他点到集合的最小距离
//4.将该点纳入集合中

#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];  //稠密图用邻接矩阵存储
int dist[N];  //存的是点到集合的距离
int res;      //所有点到集合的最小距离的总和
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist); //刚开始点都在集合外，所以都要初始化正无穷

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            //求出不在集合中的距离集合最近的点
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        //该点不是第一个点且该点距离集合无穷远,那么找不到最小生成树
        if (i && dist[t] == 0x3f3f3f3f)return 0x3f3f3f3f;
        //不是第一个点，就更新下最小生成树的距离
        if (i)res += dist[t];
        for (int j = 1; j <= n; j++)
        {
            //与dijkstra不同的是：prime是每次更新距离集合的最短距离，
            //也就是该点与集合中的某个点有连边，找到此边的长度;
            //dijkstra是每次更新点到源点（1号点）的最短距离
            dist[j] = min(dist[j], g[t][j]);
        }
        st[t] = true; //把更新过的集合外的点加到集合中
    }
    return res;
}
int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);  //因为是无向图，要建立两条边
    }
    int t = prim();
    if (t == 0x3f3f3f3f)cout << "impossible" << endl;
    else cout << t << endl;

}


