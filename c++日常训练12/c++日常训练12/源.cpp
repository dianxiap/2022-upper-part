#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() < b.size())swap(a, b);
    a = a + a;
    if (a.find(b) != -1)cout << "true";   //find函数可用于查找字符串中的子串或某一特定的字符。
    else cout << "false";
}