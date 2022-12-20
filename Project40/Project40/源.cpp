//����ͼ��������ȱ���
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N << 1], ne[N << 1], idx; //h��ͷ�ڵ㣬e�����еĽڵ㣬ne��ָ�����һ���ڵ�
int ans = N;//ʣ�������ͨ���е��������ֵ��С
bool st[N]; //��¼��û���߹��õ�
int n;

//�ڵ�佨������ߣ����������ͷ�巨
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//��uΪ���ڵ�������Ľڵ�����
int dfs(int u)
{
    //���߻�ͷ·
    st[u] = true;
    //sum��¼�����Ľڵ�����,res��¼������ͨ��
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        //ÿ�������Ͻڵ��ֵ
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            sum += s;  //�ۼӸ������ڵ�����
            res = max(res, s); //������ͨ��
        }
    }
    //�Ѹ��ڵ�u������������һ����ͨ��
    res = max(res, n - sum);
    //�������ͨ������С��
    ans = min(ans, res);
    return sum;

}

int main()
{
    cin >> n;
    //ͷ�ڵ��ʼ��-1
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);//����ͼ����˫���
    }
    //�����Ƿ�յģ����ĸ����Ѷ�����
    dfs(1);
    cout << ans << endl;
}