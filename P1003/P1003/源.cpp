#include <iostream>
using namespace std;

int a[102];
int b[102];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cin >> b[i];
    }
    int fenzi = a[0], fenmu = b[0];
    for (int i = 0; i < n - 1; i++)
    {
        fenmu *= b[i + 1];
        fenzi = fenzi * b[i + 1] + a[i + 1] * fenmu;

    }
    fenmu *= n;

    if (fenzi == 0) {
        cout << 0;
        return 0;
    }
    int i = fenzi, j = fenmu, r;
    while (j)
    {
        r = i % j;
        i = j;
        j = r;
    }
    cout << fenzi / i;
    if (fenmu / i != 1)
    {
        cout << "/" << fenmu / i;
    }
}