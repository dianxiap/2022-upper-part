#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;

void add(string str)
{
    int p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int quary(string str)
{
    int p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int n;
int main()
{
    cin >> n;
    while (n--)
    {
        string str, op;
        cin >> op >> str;
        if (op == "I")
        {
            add(str);
        }
        else
        {
            cout << quary(str) << endl;
        }
    }
}