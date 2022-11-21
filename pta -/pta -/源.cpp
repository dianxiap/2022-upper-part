#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
using namespace std;

const int N = 210;

string zhandian[N];
int zuowei[N];

int main()
{
    map<string, int>a;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> zhandian[i];
        a[zhandian[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        zuowei[i] = m;
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s1, s2;
        int ticket;
        cin >> s1 >> s2 >> ticket;
        int begin = a[s1];
        int end = a[s2];
        int min = 10000;
        for (int i = begin; i < end; i++)
        {
            if (min > zuowei[i])
            {
                min = zuowei[i];
            }
        }
        if (min >= ticket)
        {
            cout << min << " " << "YES" << endl;
            for (int i = begin; i < end; i++)
            {
                zuowei[i] -= ticket;
            }
        }
        else cout << "0 NO" << endl;
    }
}