#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'A' && s1[i] <= 'Z') {
            s1[i] = s1[i] + 32;
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] >= 'A' && s2[i] <= 'Z') {
            s2[i] = s2[i] + 32;
        }
    }
    if (s1 > s2)cout << ">" << endl;
    else if (s1 < s2)cout << "<" << endl;
    else cout << "=" << endl;
}