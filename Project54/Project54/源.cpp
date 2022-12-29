#define _CRT_SECURE_NO_WARNINGS 1
//��³˹������kruskal)�㷨
//1.�����б߰�Ȩ�ش�С��������
//2.ö��ÿ����a~b,Ȩ����c�����a��b����һ�������У��������߼��뼯���С�
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
    //����<�ţ�����w��������
    bool operator<(const Edge& W)const {
        return w < W.w;
    }
}e[N << 1];

//���鼯ģ��
int find(int x)
{
    if (p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    //0.��ʼ�����鼯
    for (int i = 1; i <= n; i++)p[i] = i;
    //1.���ߵ�Ȩ������
    sort(e, e + m);
    //2.��С����ö��ÿһ����
    for (int i = 0; i < m; i++)
    {
        int a = e[i].a, b = e[i].b, w = e[i].w;
        //�ҵ����ڵ�
        a = find(a), b = find(b);
        //��������ڵ㲻��һ��������
        if (a != b)
        {
            p[a] = b;
            res += w; //��С���������������ߵı�Ȩ֮��
            cnt++;
        }
    }
    //����ͨ
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


