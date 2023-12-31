#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 1000010;

int ne[N];
char s[N], p[N];
int n, m;

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])j = ne[j];
        if (p[i] == p[j + 1])j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])j = ne[j];
        if (s[i] == p[j + 1])j++;
        if (j == n)
        {
            cout << i - n << ' ';
            j = ne[j];
        }
    }
}