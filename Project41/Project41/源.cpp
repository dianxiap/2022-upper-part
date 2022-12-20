//数与图的广度优先遍历
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];//距离
queue<int> q;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    //从1号节点开始
    q.push(1);
    d[1] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        //从队头向下拓展
        for (int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)//没走过
            {
                d[j] = d[u] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}

int main()
{
    cin >> n >> m;
    //距离初始为-1，表示都没走过
    memset(d, -1, sizeof d);
    //每个头节点初始化为-1
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
}