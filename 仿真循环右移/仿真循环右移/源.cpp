#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include <string>
using namespace std;

int main()
{
    int b[10] = { 0 };
    int n, i = 0;
    cin >> n;
    int a[1010]={0};
    while (n--)
    {
        cin >> a[i];
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        while (a[j])
        {
            b[a[j] % 10]++;
            a[j] /= 10;
        }
    }
    int max = 0;
    for (int j = 0; j < 10; j++)
    {
        if (max <= b[j])
        {
            swap(max, b[j]);
        }
    }
    cout << max << ":";
    for (int j = 0; j < 10; j++)
    {
        if (max == b[j])
        {
            cout << " " << j;
        }
    }
}
