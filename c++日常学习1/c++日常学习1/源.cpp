#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int a[26] = { 0 };
    for (int i = 0; i < s.size(); i++) {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (a[s[i] - 'a'] == 1) {
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << "no" << endl;
}