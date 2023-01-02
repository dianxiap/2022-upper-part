#define _CRT_SECURE_NO_WARNINGS 1
//快速幂，指快速求出a^k
//3^13拆分成3^(8+4+1)：
//  利用指数的二进制13=1×2^3+1×2^2+0×2^1+1×2^0=8+4+1
#include <iostream>
using namespace std;

typedef long long LL;

void qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1)res = (LL)res * a % p;  //如果k的个位是1，就乘上对应的二进制权值
        k >>= 1;
        a = (LL)a * a % p;      //1-2-4-8-16，表示二进制权值
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, k, p;
        cin >> a >> k >> p;
        cout << qmi(a, k, p) << endl;
    }
}