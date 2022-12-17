#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 100010;
const int M = N * 31;

int a[N], res;
int son[M][2];
int idx;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
}
int query(int x)
{
    int p = 0, ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (son[p][!u])
        {
            p = son[p][!u];
            ans = ans * 2 + !u;
        }
        else
        {
            p = son[p][u];
            ans = ans * 2 + u;
        }
    }
    return ans;
}

int main()
{
    int n;;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int t = query(a[i]);
        res = max(res, a[i] ^ t);
    }
    cout << res;
}
