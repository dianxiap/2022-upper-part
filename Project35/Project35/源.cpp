#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
const int N = 100010;

int head = -1;
int e[N];
int ne[N];
int idx;

int add_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}
int add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}
int remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char c;
        int k, x;
        cin >> c;
        if (c == 'H')
        {
            cin >> x;
            add_head(x);
        }
        else if (c == 'I')
        {
            cin >> k >> x;
            add(k - 1, x);
        }
        else if (c == 'D')
        {
            cin >> k;
            if (k == 0)head = ne[head];
            remove(k - 1);
        }
    }
    for (int i = head; i != -1; i = ne[i])cout << e[i] << ' ';
}








