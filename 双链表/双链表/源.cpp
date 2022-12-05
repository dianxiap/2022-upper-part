#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int e[N]; //�洢��ֵ
int l[N]; //��ָ��
int r[N]; //��ָ��
int idx;  //�����±������ֵ

//���ܣ���ʼ��
void init() {
    r[0] = 1, l[1] = 0, idx = 2;//0���Ҳ���1��1�������0,0��ͷ��1��β����ʽ����������2��ʼ
}

/**
 * ���ܣ����±�Ϊk�Ľ������������x
 * @param k ���±�Ϊk�Ľ�����
 * @param x ��������x
 */
void add(int k, int x) {
    e[idx] = x, r[idx] = r[k], l[idx] = k, l[r[k]] = idx, r[k] = idx++;
}

/**
 * ���ܣ����±�Ϊk�Ľ��ɾ��
 * @param k
 */
void remove(int k) {
    //�ɵ�������
    r[l[k]] = r[k], l[r[k]] = l[k];
}

int main() {
    //�Ż�����
    ios::sync_with_stdio(false);
    //��ʼ��
    init();
    int m, k, x;
    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        if (op == "L") {
            cin >> x;
            //����˲�����x
            //����˾��Ǳ�ʾ��0���Ҳ����һ������
            add(0, x);
        }
        else if (op == "R") {
            cin >> x;
            //���Ҷ˲�����x
            add(l[1], x);//1�Ŷ˵����࣬�������Ҷ�
        }
        else if (op == "D") {
            cin >> k;
            remove(k + 1); //idx��2��ʼ�������±���Ҫk+1����Ŷ�
        }
        else if (op == "IL") {
            cin >> k >> x;
            add(l[k + 1], x); //�����k������Ǹ�Ԫ�ص��Ҳ��������x
        }
        else if (op == "IR") {
            cin >> k >> x;
            add(k + 1, x);  //��������
        }
    }
    //ע��˫������������,0��1��һͷһβ��idx��2��ʼ������֮����r[0]���ǿ�ʼ���б���������1�ͽ�β��
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
    cout << endl;
    return 0;
}
