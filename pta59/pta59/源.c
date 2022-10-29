#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int n, a, b, sum1 = 0, sum2 = 0;
    scanf("%d\n", &n);
    int i, toufa = 0;
    for (i = 0; i < n; i++) {
        toufa += 60;
        scanf("%d %d", &a, &b);
        sum1 += a;
        sum2 += b;
        toufa = toufa - a * 20;
        if (sum1 == sum2) {
            toufa = toufa - 30;
        }
        else if (1.0 * sum2 < 0.5 * sum1) {
            toufa = toufa - 70;
        }
    }
    if (toufa > 0)printf("+%d", toufa);
    else if (toufa < 0)printf("%d", toufa);
    else printf("--");
}
