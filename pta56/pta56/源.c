#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main() {
    int m, n, j = 1;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        j = m * j;
        j %= 1000;
    }
    if (j < 10)printf("00%d", j);
    else if (j < 100)printf("0%d", j);
    else printf("%d", j);

    return 0;
}