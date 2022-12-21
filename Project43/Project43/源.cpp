#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(string start)
{
    //����Ŀ��״̬
    string end = "12345678x";
    //������к�dist����
    queue<string> q;
    unordered_map<string, int> d;
    //��ʼ�����к�dist����
    q.push(start);
    d[start] = 0;
    //ת�Ʒ�ʽ
    int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        //��¼��ǰ״̬�ľ��룬���������״̬�򷵻ؾ���
        int distance = d[t];
        if (t == end) return distance;
        //��ѯx���ַ����е��±꣬Ȼ��ת��Ϊ�ھ����е�����
        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i++)
        {
            //��ת�ƺ�x������
            int a = x + dx[i], b = y + dy[i];
            //��ǰ����û��Խ��
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                //ת��x
                swap(t[k], t[a * 3 + b]);
                //�����ǰ״̬�ǵ�һ�α�������¼���룬���
                if (!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                //��ԭ״̬��Ϊ��һ��ת�������׼��
                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    //�޷�ת����Ŀ��״̬������-1
    return -1;
}

int main()
{
    string c, start;
    //������ʼ״̬
    for (int i = 0; i < 9; i++)
    {
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;

    return 0;
}

