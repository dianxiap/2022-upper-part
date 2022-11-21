#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
int main() {
    int n, sn = 0;
    scanf("%d", &n);
    int i, j, liu = 0, t = 1;
    for (i = 0; i < n; i++) {
        t = 1, liu = 0;
        for (j = i; j < n; j++) {
            int m = t * 2;
            liu += m;
            t *= 10;
        }
        sn += liu;
    }
    printf("%d", sn);
}