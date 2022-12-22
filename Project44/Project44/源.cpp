#define _CRT_SECURE_NO_WARNINGS 1
//���Ż����dijkstra�Ƕ����ذ�dijkstra�������Ż��������ذ�dijkstra��ʱ�临�Ӷ���ߵ�Ѱ�Ҿ���
//��̵ĵ�O(n^2)����ʹ����С���Ż���
//1. һ�ŵ�ľ����ʼ��Ϊ�㲢����ѣ��������ʼ���������
//2. ����ѭ����ֱ���ѿա�ÿһ��ѭ����ִ�еĲ���Ϊ��
//    ȡ���Ѷ��ĵ�͵�ľ��룬�øõ���¸õ�ָ��ĵ����С���룬�����³ɹ��ͼ��뵽���С�

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;  //ÿ����͵��Դ��ľ������һ��pair
const int N = 1000010;

int h[N], e[N], ne[N], w[N], idx;//����ͼ���ڽӱ�
int dist[N];  //��¼ÿ���㵽Դ��ľ���
bool st[N];   //�ж�ÿ�������̾����Ƿ�ȷ��
int n, m;


void add(int a, int b, int c)  //�����
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);  //��1�ŵ��ʼΪ�����
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;  //С���ѣ��̶�д��
    heap.push({ 0,1 });  //first�洢�ڵ���룬second�洢�ڵ���

    while (heap.size())
    {
        auto t = heap.top();  //ȡ����,�������Ǿ�����С�ĵ�
        heap.pop();

        int ver = t.second, distence = t.first;  //ver�ڵ��ţ�distence�ڵ����

        if (st[ver])continue;  //��ʾ�Ѿ�������ˣ�ʣ�µ������౸�ݣ������ر�
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])  //����verָ��Ľڵ�
        {
            int j = e[i];
            if (dist[j] > distence + w[i])  //1�ŵ㵽��j �� 1�ž���ver����j�ľ���
            {
                dist[j] = distence + w[i];
                heap.push({ dist[j],j });  //���º����̾�������
            }
        }

    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;
}




