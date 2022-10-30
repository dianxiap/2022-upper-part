#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    char b;
    cin >> b;
    for (char& c : s) {
        if (c == b)c = '#';
    }
    cout << s << endl;
}