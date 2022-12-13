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
int g[N][N];//地图
int d[N][N];//距离
PII q[N * N];//为啥是N*N? 因为q代表可能走到的地图的每一个点,是长x宽

int bfs() {
    int hh = 0, tt = 0;
    q[0] = { 0,0 };//把起点放进去

    memset(d, -1, sizeof d);//初始化为-1,表示没有来过
    d[0][0] = 0;//起点的步数为0

    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };//左上右下

    while (hh <= tt) {
        auto t = q[hh++];//拿到对头,顺便将对头出列

        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)//可以走,并且没走过
            {
                d[x][y] = d[t.x][t.y] + 1;
                q[++tt] = { x,y };
            }
        }
    }
    return d[n - 1][m - 1];//输出一个整数，表示从左上角移动至右下角的最少移动次数。
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