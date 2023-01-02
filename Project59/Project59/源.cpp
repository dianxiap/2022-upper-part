#define _CRT_SECURE_NO_WARNINGS 1
//�����ݣ�ָ�������a^k
//3^13��ֳ�3^(8+4+1)��
//  ����ָ���Ķ�����13=1��2^3+1��2^2+0��2^1+1��2^0=8+4+1
#include <iostream>
using namespace std;

typedef long long LL;

void qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1)res = (LL)res * a % p;  //���k�ĸ�λ��1���ͳ��϶�Ӧ�Ķ�����Ȩֵ
        k >>= 1;
        a = (LL)a * a % p;      //1-2-4-8-16����ʾ������Ȩֵ
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