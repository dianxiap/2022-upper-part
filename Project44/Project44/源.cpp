#define _CRT_SECURE_NO_WARNINGS 1
//堆优化版的dijkstra是对朴素版dijkstra进行了优化，在朴素版dijkstra中时间复杂度最高的寻找距离
//最短的点O(n^2)可以使用最小堆优化。
//1. 一号点的距离初始化为零并放入堆，其他点初始化成无穷大。
//2. 不断循环，直到堆空。每一次循环中执行的操作为：
//    取出堆顶的点和点的距离，用该点更新该点指向的点的最小距离，若更新成功就加入到堆中。

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;  //每个点和点距源点的距离记作一对pair
const int N = 1000010;

int h[N], e[N], ne[N], w[N], idx;//疏密图用邻接表
int dist[N];  //记录每个点到源点的距离
bool st[N];   //判断每个点的最短距离是否确定
int n, m;


void add(int a, int b, int c)  //插入边
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);  //除1号点初始为无穷大
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;  //小根堆，固定写法
    heap.push({ 0,1 });  //first存储节点距离，second存储节点编号

    while (heap.size())
    {
        auto t = heap.top();  //取根顶,根顶就是距离最小的点
        heap.pop();

        int ver = t.second, distence = t.first;  //ver节点编号，distence节点距离

        if (st[ver])continue;  //表示已经处理过了，剩下的是冗余备份，比如重边
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])  //更新ver指向的节点
        {
            int j = e[i];
            if (dist[j] > distence + w[i])  //1号点到点j 和 1号经过ver到点j的距离
            {
                dist[j] = distence + w[i];
                heap.push({ dist[j],j });  //更新后的最短距离放入堆
            }
        }

    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;
}




