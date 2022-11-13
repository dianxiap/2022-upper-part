#include <iostream>
using namespace std;

const int N = 100010;

void quicksort(int p[], int l, int r);

int main()
{
    int n, k, p[N];
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> p[i];
    quicksort(p, 0, n - 1);
    cout << p[k - 1];
}
void quicksort(int p[], int l, int r)
{
    if (l >= r)return;
    int i = l - 1, j = r + 1, x = p[l + r >> 1];
    while (i < j)
    {
        do i++; while (p[i] < x);
        do j--; while (p[j] > x);
        if (i < j)swap(p[i], p[j]);
    }
    quicksort(p, l, j);
    quicksort(p, j + 1, r);
}