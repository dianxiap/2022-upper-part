#include <iostream>
#include<cmath>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        cin >> a;
        if (a) {
            if (i != n && a > 0)cout << "+";   // 根据正负、是否为最高此项决定加号
            if (abs(a) > 1 || i == 0)cout << a;    
            if (a == -1 && i)cout << "-";    //-1系数特判，常数项已特判
            if (i > 1)cout << "x^" << i;   // 
            if (i == 1)cout << "x";   // 一次项
        }
    }
}