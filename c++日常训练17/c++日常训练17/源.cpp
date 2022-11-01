#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int n, m;
int res;                  // res ���

void dfs(int x, int y)    // ���Ѻ���
{
    if (x == n && y == m) // ����ѵ��˵� (n, m), ��ô res ++ ������
    {
        res++;
    }
    if (x < n) dfs(x + 1, y); // �������������ĵ㣬��ô�Ѹõ�����ĵ�
    if (y < m) dfs(x, y + 1); // ����������ұߵĵ㣬��ô�Ѹõ��ұߵĵ�
}

int main()
{
    scanf("%d %d", &n, &m);
    dfs(0, 0);            // �ӵ� (0, 0) ��ʼ����
    printf("%d\n", res);
    return 0;
}
