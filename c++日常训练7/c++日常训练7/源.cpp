#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1;
    getline(cin, s1);
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z')s1[i] = (s1[i] - 'a' + 1) % 26 + 'a';
        else if (s1[i] >= 'A' && s1[i] <= 'Z')s1[i] = (s1[i] - 'A' + 1) % 26 + 'A';
    }
    cout << s1 << endl;
}