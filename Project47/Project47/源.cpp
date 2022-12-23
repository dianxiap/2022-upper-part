#define _CRT_SECURE_NO_WARNINGS 1
//spfs--（bellman_ford的优化版本）
//1.初始话无穷大
//2.用可以更新其他点的点去更新

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];  //判断该点是否在队列中

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);  //1.初始化无穷大
    dist[1] = 0;
    queue<int> q;  //队列中存储可以更新其他点的点
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])  //2.用可以更新其他点的点t去更新
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])    //如果点j不再队列里就加进去
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }

    }
    return dist[n];
}


int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int t = spfa();
    if (t == 0x3f3f3f3f)puts("impossible");
    else cout << t;
}


#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N], cnt[N];  //cnt[N]记录当前这个点的最短路所经过的边数
bool st[N];  //判断这个点是否在队列里

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    //这时候不用初始化距离，因为看的是点的边的状态
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        st[i] = true;  //负环不一定从1开始，可能从任意点开始，所以把所有点都加到队列中
        q.push(i);
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)return true;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    if (spfa())puts("Yes");
    else cout << "No";

}