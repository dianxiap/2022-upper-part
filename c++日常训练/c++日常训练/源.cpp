#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, l;
    int max = 0;
    while (cin >> a) {
        int len = a.size();
        if (a[len - 1] == '.') {
            a.erase(len - 1, 1);  //ɾ����len-1��ʼ��1�����ȵ��ַ�
            len--;
        }
        if (max < len) {
            max = len;
            l = a;
        }
    }
    cout << l;
}