#include <iostream>
using namespace std;
int main() {
    int n, gap[101];
    int h[100] = { 0 }, m[100] = { 0 }, s[100] = { 0 }, i = 1;
    int f[101], a[101], sum = 0;
    scanf_s("%d", &n);
    while (n--) {
        scanf_s("%d:%d:%d", &h[i], &m[i], &s[i]);
        cin >> f[i] >> a[i];
        i++;
    }
    for (int j = 2;j < i;j++) {
        gap[j] = (h[j] - h[j - 1]) * 3600 + (m[j] - m[j - 1]) * 60 + s[j] - s[j - 1];
        sum += gap[j]*f[j-1]*a[j-1];
    }
   
    printf("%d", sum);
}