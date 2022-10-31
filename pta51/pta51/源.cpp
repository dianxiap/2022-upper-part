#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    while (cin >> s, s[0] != '#') {
        int p = 0;
        char c[100];
        int num = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';  //将数字字符全转为整形
            }
            else {
                p = 1;
                num = num * 26 + s[i] - 'A' + 1;  //将字母字符转为整形，也就是将列名转为列序号
            }
        }
        if (p)cout << num << endl;
        else {
            while (num) {
                if (num % 26 == 0) {   //将数字合再转为字母
                    c[cnt] = 'Z';
                    cnt++;
                    num /= 26;
                    num--;
                }
                else {
                    c[cnt] = 'A' + num % 26 - 1;
                    num /= 26;
                    cnt++;
                }
            }
            for (int j = cnt - 1; j >= 0; j--) {
                cout << c[j];
            }
            cout << endl;
        }
    }
}