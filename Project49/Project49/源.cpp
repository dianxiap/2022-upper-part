#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>

using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int g[N][N];    //����ͼ���ڽӾ���
int dist[N];    //����㵽���ϵľ���
bool st[N];     //�ǲ����Ѿ�ʹ�ù�
int res;        //��С����������ߵĳ���֮��

/**
 * ���ܣ�����ķ�㷨����С������
 * @return
 */
int prim() {
    //����n��
    for (int i = 0; i < n; i++) {
        //1���ҵ������⣬���뼯������ĵ�
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        /*������ǵ�һ���㣬���Ҿ�����INF��˵������û�е������ͨ����������
         ��ʱ������ͨͼ��û����С������������INF*/
        if (i && dist[t] == INF) return INF;
        /*�ǵ�һ����㣬dist[1]Ӧ����0,���ڳ�ʼ������INF,������������һ�¡�
        ���ǵ�һ����,������������ߵ�Ȩֵ��*/
        if (i)res += dist[t];
        //2����Ϊ����ѡ����ǽ��t,��ô��t��������δ���뵽�����е㵽���ϵľ���
        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
        //3����t�ŵ�������
        st[t] = true;
    }
    return res;
}

int main() {
    //�����Ż�
    ios::sync_with_stdio(false);
    cin >> n >> m;
    //���е�֮��ľ����ʼ��Ϊ�����Ȼ���ٶ������б�
    memset(g, 0x3f, sizeof g);
    //�����ʼ�������,��ʾ���н�㶼��������֮��
    memset(dist, 0x3f, sizeof dist);
    //��������
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
        //�����ظ�������˫�������Ϊ����ͼ,ͬʱ������С��
    }
    int t = prim();//����ķ�㷨
    //������
    if (t == INF) puts("impossible");
    //���������������������е㲻��ͨ�������
    else printf("%d\n", t); //�������t

    return 0;
}

