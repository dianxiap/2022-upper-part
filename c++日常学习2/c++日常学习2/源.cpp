#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str, substr;
    while (cin >> str >> substr) {
        int max = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[max] < str[i]) {
                max = i;
            }
        }
        str = str.insert(max + 1, substr);
        cout << str << endl;
    }
}