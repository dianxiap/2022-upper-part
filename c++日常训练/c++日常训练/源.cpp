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
            a.erase(len - 1, 1);  //删除从len-1开始，1个长度的字符
            len--;
        }
        if (max < len) {
            max = len;
            l = a;
        }
    }
    cout << l;
}