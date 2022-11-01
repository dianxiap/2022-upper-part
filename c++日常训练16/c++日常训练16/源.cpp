#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

const int N = 200;

string s[N];

int n;

int main() {

    while (cin >> n, n) {

        int len = 201;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            if (len > s[i].size())len = s[i].size();               //�ҳ���̵��ַ���
        }

        while (len) {
            bool success = true;
            for (int i = 1; i < n; i++) {

                bool same = true;

                for (int j = 1; j <= len; j++) {
                    if (s[0][s[0].size() - j] != s[i][s[i].size() - j]) {     //��ĩβ�ж���ͬ���ַ�������ǰ�жϵ����ֲ�ͬ���ַ�ʱ������Ҫ�����жϵĺ�׺��������1
                        same = false;
                        break;
                    }
                }
                if (!same) {
                    success = false;
                    break;
                }
            }
            if (success)break;
            len--;

        }
        cout << s[0].substr(s[0].size() - len) << endl;           //��ȡ�����ظ��Ӵ�
    }
}