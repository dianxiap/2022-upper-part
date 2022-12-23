#define _CRT_SECURE_NO_WARNINGS 1
//��Ȩ��--bellman_ford�㷨��
//1.����k���ߣ����������
//2.�������бߵ���̾���

#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 10010;

struct Edge
{
    int a;
    int b;
    int w;
}e[M];  //��¼��ͱ�Ȩ

int n, m, k;
int dist[N];  //����
int backup[N];  //����ı���

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)  //ѭ��k��
    {
        memcpy(backup, dist, sizeof dist);  //���ݾ��룬ʹÿ��ѭ��ֻ����һ����ľ���
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
    if (dist[n] > 0x3f3f3f3f / 2)puts("impossible");  //dist[n]���ܱ���һ������¹������ܲ��������
    else cout << dist[n];

}


