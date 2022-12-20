//树与图的深度优先遍历
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N << 1], ne[N << 1], idx; //h存头节点，e存所有的节点，ne存指向的下一个节点
int ans = N;//剩余各个连通块中点数的最大值最小
bool st[N]; //记录有没有走过该点
int n;

//节点间建立单向边，采用链表的头插法
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//以u为根节点的子树的节点数量
int dfs(int u)
{
    //不走回头路
    st[u] = true;
    //sum记录子树的节点数量,res记录最大的连通块
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        //每条链表上节点的值
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            sum += s;  //累加该子树节点总数
            res = max(res, s); //最大的连通块
        }
    }
    //把根节点u所在子树看成一个连通块
    res = max(res, n - sum);
    //找最大连通块中最小的
    ans = min(ans, res);
    return sum;

}

int main()
{
    cin >> n;
    //头节点初始化-1
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);//无向图，建双向边
    }
    //此数是封闭的，从哪个点搜都可以
    dfs(1);
    cout << ans << endl;
}