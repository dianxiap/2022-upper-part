#define _CRT_SECURE_NO_WARNINGS 1
//״̬��ʾ��f[i][j]����ʾ����i��j)����������·���ļ��ϣ�����Ϊ���ֵ
//״̬���㣺�����е���i��j�����·����Ϊ���������ĺʹ��������ģ�״̬ת�Ʒ���Ϊ��f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);

#include <iostream>
using namespace std;

const int N = 510, INF = 1e9;

int a[N][N];
int f[N][N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)  //���ǵ��Ǵ����Ϻ������������ģ�Ӧ�ý��߽�����һ��
            f[i][j] = -INF;
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
    int res = -INF;
    for (int i = 1; i <= n; i++)res = max(res, f[n][i]);
    cout << res;
}