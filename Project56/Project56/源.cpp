#define _CRT_SECURE_NO_WARNINGS 1
����ɸ��
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int primes[N], cnt;     // primes[]�洢��������
bool st[N];             // st[x]�洢x�Ƿ�ɸ��
//����ɸ
void get_primes(int n) {
    for (int i = 2; i <= n; i++)
        if (!st[i]) {
            primes[cnt++] = i;   //��¼����
            for (int j = 2 * i; j <= n; j += i) //�ɱ����ı�ʶ
                st[j] = true;
        }
}

ŷ��ɸ[����ɸ��]
int main() {
    //�����Ż�
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int primes[N], cnt;
bool st[N];
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        bool flag = (primes[0] * i <= n);
        if (flag) printf("i=%d ", i);
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;
            printf("%d ", primes[j] * i);
            if (i % primes[j] == 0) break;
        }
        if (flag) puts("");
    }
}

int main() {
    get_primes(200);
    return 0;
}