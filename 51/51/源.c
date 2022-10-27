#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
void lieming(char p[]) {
    int sum = 0;
    int m;
    m= strlen(p);
    for (int i = 0; i < m; i++) {
        sum = sum * 26 + p[i] - 'A' + 1;
    }
    printf("%d", sum);
}
void liexuhao(char *p) {
    int m;
    m= strlen(p);
    int n = 0, j = 1, i;
    for (i = 0; i < m - 1; i++) {
        j = j * 10;
    }
    for (i = 0; i < m; i++) {
        n = n + (p[i] - '0') * j;
        j /= 10;
    }
    char c[6] = { '\0' };
    int q = 0;
    while (n != 0) {
        int x = n % 26;
        n = n / 26;
        if (x != 0) {
            c[q] = x - 1 + 'A';
            q++;
        }
        else {
            c[q] = 'Z';
            q++;
            n--;
        }
    }
    for (i = m; i >= 0; i--) {
        printf("%c", c[i]);
    }
}
int main() {
    char ch[6]={0};
    while (1) {
        scanf("%s", ch);
        int i = 0;
        if (ch[i] <= 'Z' && ch[i] >= 'A') {
            lieming(ch);
            printf("\n");
        }
        else if (ch[i] >= '0' && ch[i] <= '9') {
            liexuhao(ch);
            printf("\n");
        }
        if (ch[0] == '#')
            break;
        i++;
    }

}