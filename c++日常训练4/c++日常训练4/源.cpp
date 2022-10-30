#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    double a;
    string b, c;
    cin >> a >> b >> c;
    double d = 0.0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == c[i])d++;
    }
    d = d / b.size();
    if (d >= a)cout << "yes" << endl;
    else cout << "no" << endl;
}