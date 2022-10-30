#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            cout << ' ';
            while (s[i + 1] == ' ') {
                i++;
            }
        }
        else cout << s[i];
    }
}