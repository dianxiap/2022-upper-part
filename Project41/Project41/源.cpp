//����ͼ�Ĺ�����ȱ���
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];//����
queue<int> q;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    //��1�Žڵ㿪ʼ
    q.push(1);
    d[1] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        //�Ӷ�ͷ������չ
        for (int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)//û�߹�
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
    //�����ʼΪ-1����ʾ��û�߹�
    memset(d, -1, sizeof d);
    //ÿ��ͷ�ڵ��ʼ��Ϊ-1
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
}