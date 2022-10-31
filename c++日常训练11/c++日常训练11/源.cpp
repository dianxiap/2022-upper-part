#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a[100];
    int i = 0;
    while (cin >> a[i]) {
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << a[j] << ' ';
    }
}