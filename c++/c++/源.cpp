#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    int n;
    cin >> n;
    while (n--) {
        int count = 0, max = 1;
        cin >> a;
        char c = a[0];
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == a[i + 1]) {
                count++;
                if (max <= count) {
                    max = count + 1;
                    c = a[i];
                }
            }
            else count = 0;
        }
        cout << c << ' ' << max << endl;
    }
}
