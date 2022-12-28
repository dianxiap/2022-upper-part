#define _CRT_SECURE_NO_WARNINGS 1
//prim�㷨������˼·��dijkstra�㷨˼·��ͬ��
//1.��ʼ��������
//2.������ڼ����еľ��뼯������ĵ�
//3.�øõ���������㵽���ϵ���С����
//4.���õ����뼯����

#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];  //����ͼ���ڽӾ���洢
int dist[N];  //����ǵ㵽���ϵľ���
int res;      //���е㵽���ϵ���С������ܺ�
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist); //�տ�ʼ�㶼�ڼ����⣬���Զ�Ҫ��ʼ��������

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            //������ڼ����еľ��뼯������ĵ�
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        //�õ㲻�ǵ�һ�����Ҹõ���뼯������Զ,��ô�Ҳ�����С������
        if (i && dist[t] == 0x3f3f3f3f)return 0x3f3f3f3f;
        //���ǵ�һ���㣬�͸�������С�������ľ���
        if (i)res += dist[t];
        for (int j = 1; j <= n; j++)
        {
            //��dijkstra��ͬ���ǣ�prime��ÿ�θ��¾��뼯�ϵ���̾��룬
            //Ҳ���Ǹõ��뼯���е�ĳ���������ߣ��ҵ��˱ߵĳ���;
            //dijkstra��ÿ�θ��µ㵽Դ�㣨1�ŵ㣩����̾���
            dist[j] = min(dist[j], g[t][j]);
        }
        st[t] = true; //�Ѹ��¹��ļ�����ĵ�ӵ�������
    }
    return res;
}
int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);  //��Ϊ������ͼ��Ҫ����������
    }
    int t = prim();
    if (t == 0x3f3f3f3f)cout << "impossible" << endl;
    else cout << t << endl;

}


