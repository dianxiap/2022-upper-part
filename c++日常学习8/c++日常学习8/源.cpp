#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    string b;
    getline(cin, a);
    for (int i = 0; i < a.size(); i++) {
        cout << (char)(a[i] + a[(i + 1) % a.size()]);
    }
}