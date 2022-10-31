#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a[1000], b, c;
    int i = 0;
    while (cin >> a[i]) {  //输入每个单词
        i++;
        char d = getchar();
        if (d == '\n') {
            break;
        }
    }
    cin >> b >> c;
    for (int j = 0; j < i; j++) {
        if (a[j] == b) {
            cout << c << ' ';
        }
        else cout << a[j] << ' ';
    }
}