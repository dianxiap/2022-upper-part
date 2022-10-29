#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 500
int main() {
    int n;
    scanf("%d", &n);
    int gongji, muji, xiaoji;
    int count = 0;
    int i = 0, sum = 0;
    for (gongji = 0; gongji <= n / 5; gongji++) {
        for (muji = 0; muji <= n / 3; muji++) {
            xiaoji = n - gongji - muji;
            if (5 * gongji + 3 * muji + xiaoji / 3.0 == n) {
                count++;
                sum += gongji;
                break;
            }
        }

    }
    if (count) {
        printf("%d %d", count, sum);
    }
    else printf("0 -1");
    return 0;
}