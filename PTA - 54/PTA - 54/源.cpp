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
    map<char, int> m;  //������±�
    reverse(b.begin(), b.end());  //�����λ��ʼ��
    reverse(c.begin(), c.end());
    for (int i = 0; i < len; i++)
    {
        m[a[i]] = i;  //���±�
    }
    int i, t = 0;
    string d = "";
    for (i = 0; i < b.size() || i < c.size(); i++)
    {
        if (i < b.size())t += m[b[i]];  //�ӷ�����
        if (i < c.size())t += m[c[i]];
        d += a[t % len];
        t /= len;   //��λ
    }
    if (t)d += a[1];
    reverse(d.begin(), d.end());  //�ӵ���λ����תһ��
    cout << d;
}