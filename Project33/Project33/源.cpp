#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 110;
int n, m;
int g[N][N];//��ͼ
int d[N][N];//����
PII q[N * N];//Ϊɶ��N*N? ��Ϊq��������ߵ��ĵ�ͼ��ÿһ����,�ǳ�x��

int bfs() {
    int hh = 0, tt = 0;
    q[0] = { 0,0 };//�����Ž�ȥ

    memset(d, -1, sizeof d);//��ʼ��Ϊ-1,��ʾû������
    d[0][0] = 0;//���Ĳ���Ϊ0

    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };//��������

    while (hh <= tt) {
        auto t = q[hh++];//�õ���ͷ,˳�㽫��ͷ����

        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)//������,����û�߹�
            {
                d[x][y] = d[t.x][t.y] + 1;
                q[++tt] = { x,y };
            }
        }
    }
    return d[n - 1][m - 1];//���һ����������ʾ�����Ͻ��ƶ������½ǵ������ƶ�������
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}