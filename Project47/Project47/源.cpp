#define _CRT_SECURE_NO_WARNINGS 1
//spfs--��bellman_ford���Ż��汾��
//1.��ʼ�������
//2.�ÿ��Ը���������ĵ�ȥ����

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];  //�жϸõ��Ƿ��ڶ�����

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);  //1.��ʼ�������
    dist[1] = 0;
    queue<int> q;  //�����д洢���Ը���������ĵ�
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])  //2.�ÿ��Ը���������ĵ�tȥ����
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])    //�����j���ٶ�����ͼӽ�ȥ
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
int dist[N], cnt[N];  //cnt[N]��¼��ǰ���������·�������ı���
bool st[N];  //�ж�������Ƿ��ڶ�����

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    //��ʱ���ó�ʼ�����룬��Ϊ�����ǵ�ıߵ�״̬
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        st[i] = true;  //������һ����1��ʼ�����ܴ�����㿪ʼ�����԰����е㶼�ӵ�������
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