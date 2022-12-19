#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
const int N = 10;

char g[N][N];
int n;
bool row[N], col[N], ge[N * 2], uge[N * 2];

void dfs(int x, int y, int s)
{
    if (y == n)y = 0, x++;
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)puts(g[i]);
            puts("");
            return;
        }
    }
    dfs(x, y + 1, s);
    if (!row[x] && !col[y] && !ge[x + y] && !uge[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = ge[x + y] = uge[x - y + n] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = ge[x + y] = uge[x - y + n] = false;
        g[x][y] = '.';
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }
    dfs(0, 0, 0);
}


