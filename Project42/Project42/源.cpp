//����ͼ����������
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;

int n, m;  //����������
int d[N]; //���е�����
int h[N], e[N], ne[N], idx;
int q[N]; //����ģ�����

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;//��ʼ������
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])q[++tt] = i; //���Ϊ��ĵ������
    }
    while (hh <= tt)
    {
        int t = q[hh++]; //ȡ��ͷ
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--; //ɾ����һ����iָ��õ�j�ı�
            if (d[j] == 0)q[++tt] = j;
        }
    }
    return tt == n - 1; //n���㶼����ˣ���Ϊ������
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    //��a,b�佨�������
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;  //��¼ÿ��������
    }
    if (topsort())
    {
        for (int i = 0; i < n; i++)cout << q[i] << ' ';
        cout << endl;
    }
    else cout << "-1";
}