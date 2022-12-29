#define _CRT_SECURE_NO_WARNINGS 1
//克鲁斯卡尔（kruskal)算法
//1.将所有边按权重从小到大排序
//2.枚举每条边a~b,权重是c，如果a，b不在一个集合中，将这条边加入集合中。
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, m;
int p[N];
int res, cnt;

struct Edge
{
    int a, b, w;
    //重载<号，利用w进行排序
    bool operator<(const Edge& W)const {
        return w < W.w;
    }
}e[N << 1];

//并查集模板
int find(int x)
{
    if (p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    //0.初始化并查集
    for (int i = 1; i <= n; i++)p[i] = i;
    //1.按边的权重排序
    sort(e, e + m);
    //2.从小到大枚举每一条边
    for (int i = 0; i < m; i++)
    {
        int a = e[i].a, b = e[i].b, w = e[i].w;
        //找到根节点
        a = find(a), b = find(b);
        //如果两个节点不在一个集合中
        if (a != b)
        {
            p[a] = b;
            res += w; //最小生成树中所有树边的边权之和
            cnt++;
        }
    }
    //不连通
    if (cnt < n - 1)return 0x3f3f3f3f;
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = { a,b,w };
    }
    int t = kruskal();
    if (t == 0x3f3f3f3f)cout << "impossible" << endl;
    else cout << t;
}


