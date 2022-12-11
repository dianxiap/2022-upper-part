
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 100010;

int heap[N], ph[N], hp[N], sz;

void heap_swap(int a, int b)
{
    swap(heap[a], heap[b]);
    swap(hp[a], hp[b]);
    swap(ph[hp[a]], ph[hp[b]]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= sz && heap[u * 2] < heap[t])t = u * 2;
    if (u * 2 + 1 <= sz && heap[u * 2 + 1] < heap[t])t = u * 2 + 1;
    if (t != u)
    {
        heap_swap(t, u);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && heap[u] < heap[u / 2])
    {
        heap_swap(u, u / 2);
        u /= 2;
    }
}

int n, m;
int main()
{
    cin >> n;
    while (n--)
    {
        string op;
        int k, x;
        cin >> op;
        if (op == "I")
        {
            cin >> x;
            m++;
            sz++;
            ph[m] = sz;
            hp[sz] = m;
            heap[sz] = x;
            up(sz);
        }
        else if (op == "PM")cout << heap[1] << endl;
        else if (op == "DM")
        {
            heap_swap(1, sz);
            sz--;
            down(1);
        }
        else if (op == "D")
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, sz);
            sz--;
            down(k);
            up(k);
        }
        else if (op == "C")
        {
            cin >> k >> x;
            k = ph[k];
            heap[k] = x;
            down(k);
            up(k);
        }
    }
}