#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void isFactorOf(int x, int y) {
    if (x % y) printf("%d is not a factor of %d.\n", y, x);
    else printf("%d is a factor of %d.\n", y, x);
}
void proceed(int* a, int* b, int size, void (*fp)(int x, int y));
int main()
{
    int n;
    scanf("%d", &n);
    int a[100], b[100];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    proceed(a, b, n, isFactorOf);
    return 0;
}
/* 你的代码将被嵌到这里 */
void proceed(int* a, int* b, int size, void (*fp)(int x, int y)) {
    int i = 0;
    for (i = 0; i < size; i++) {
        (*fp)(a[i], b[i]);
    }
}
