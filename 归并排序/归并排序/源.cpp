#include <iostream>
using namespace std;

const int N = 100010;

int p[N], tem[N];

void merge(int q[], int l, int r);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> p[i];
    merge(p, 0, n - 1);
    for (int i = 0; i < n; i++)cout << p[i] << ' ';
}
void merge(int q[], int l, int r)
{
    if (l >= r)return;
    int mid = l + r >> 1;
    merge(q, l, mid);
    merge(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])tem[k++] = q[i++];
        else tem[k++] = q[j++];
    while (i <= mid)tem[k++] = q[i++];
    while (j <= r)tem[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++)q[i] = tem[j];
}