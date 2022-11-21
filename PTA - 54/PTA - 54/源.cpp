#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    int len = a.size();
    map<char, int> m;  //存进制下表
    reverse(b.begin(), b.end());  //从最低位开始加
    reverse(c.begin(), c.end());
    for (int i = 0; i < len; i++)
    {
        m[a[i]] = i;  //存下标
    }
    int i, t = 0;
    string d = "";
    for (i = 0; i < b.size() || i < c.size(); i++)
    {
        if (i < b.size())t += m[b[i]];  //加法函数
        if (i < c.size())t += m[c[i]];
        d += a[t % len];
        t /= len;   //进位
    }
    if (t)d += a[1];
    reverse(d.begin(), d.end());  //加到高位，翻转一下
    cout << d;
}