#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];  //�ڽӾ��󣬴���Ǵӵ�N����N�ľ���
int dist[N];  //��¼ÿһ���㵽��һ����ľ���
bool st[N];  //��¼ÿ�������̾����Ƿ�ȷ����

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist); //��ʼʱ���е����1�ŵ���������
    dist[1] = 0;  //1�ŵ�����������Ϊ0
    for (int i = 1; i <= n; i++)  //ѭ��n��
    {
        //�ҵ���ǰδȷ�����·���ĵ��о�����̵ĵ�
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            //!st[j]�ж��Ƿ�Ϊδȷ�����·���ĵ�
            //(dist[t]>dist[j)�ҳ�������̵ĵ�
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;  //��ʾ�õ�����·��ȷ����
        for (int j = 1; j <= n; j++)
        {
            //��t������е����̾������¸���һ�飺�Ƚϴ�1�ŵ㵽j�ŵ� �� ��1�ŵ㵽t�ŵ��ٵ�j�ŵ�ľ���
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);  //��ʼʱ1����Ϊ1�ŵ�0���������1�ŵ���������

    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);//���ر����Ҿ�����̵�һ����
    }
    cout << dijkstra() << endl;
}

