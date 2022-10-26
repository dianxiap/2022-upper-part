#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char n[501];
int main() {
    char ch[10][10] = { "0 ","1,.?!","2ABC","3DEF","4GHI","5JKL","6MNO",
                   "7PQRS","8TUV","9WXYZ" };
    char ch2[500];
    int q;
    gets(n);
    int m = strlen(n);
    int i, k = 0;
    for (i = 0; i < m;) {
        int q, p = 0, count = 0;
        if (n[i] >= '0' && n[i] <= '9') {
            q = n[i] - '0';
            while (n[i] >= '0' && n[i] <= '9') {
                count++;
                i++;
            }

            p = strlen(ch[q]);
            count = count % strlen(ch[q]);
            if (count == 0) {
                ch2[k++] = ch[q][p - 1];
            }
            else {
                ch2[k++] = ch[q][count - 1];
            }
        }
        else i++;
    }
    for (i = 0; i < k; i++) {
        printf("%c", ch2[i]);
    }
    return 0;
}