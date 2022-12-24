#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>

using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int g[N][N];    //稠密图，邻接矩阵
int dist[N];    //这个点到集合的距离
bool st[N];     //是不是已经使用过
int res;        //最小生成树里面边的长度之和

/**
 * 功能：普利姆算法求最小生成树
 * @return
 */
int prim() {
    //迭代n次
    for (int i = 0; i < n; i++) {
        //1、找到集合外，距离集合最近的点
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        /*如果不是第一个点，并且距离是INF，说明现在没有点可以连通到生成树，
         这时不是连通图，没有最小生成树，返回INF*/
        if (i && dist[t] == INF) return INF;
        /*是第一个结点，dist[1]应该是0,现在初始化的是INF,所有这里特判一下。
        不是第一个点,结果加上这条边的权值。*/
        if (i)res += dist[t];
        //2、因为本轮选择的是结点t,那么用t更新其它未加入到集合中点到集合的距离
        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
        //3、把t放到集合中
        st[t] = true;
    }
    return res;
}

int main() {
    //读入优化
    ios::sync_with_stdio(false);
    cin >> n >> m;
    //所有点之间的距离初始化为正无穷，然后再读入所有边
    memset(g, 0x3f, sizeof g);
    //距离初始化无穷大,表示所有结点都在生成树之外
    memset(dist, 0x3f, sizeof dist);
    //读入数据
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
        //允许重复，构建双向有向成为无向图,同时保留最小的
    }
    int t = prim();//普利姆算法
    //输出结果
    if (t == INF) puts("impossible");
    //不存在生成树，比如所有点不连通的情况下
    else printf("%d\n", t); //否则输出t

    return 0;
}

