#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {

    char buf1[1001] = { 0 };
    char buf2[10001] = { 0 };
    while (scanf("%s", buf1) != EOF) {
        scanf("%s", buf2);

        char array[10002] = { 0 };
        int i, j;
        for (i = strlen(buf1) - 1, j = 0; i >= 0, j < strlen(buf1); i--, j++) {
            array[j] = buf1[i] - 0x30;
        }

        for (i = strlen(buf2) - 1, j = 0; i >= 0, j < strlen(buf2); i--, j++) {
            array[j] += buf2[i] - 0x30;
            if (array[j] > 9) {
                array[j] %= 10;
                array[j + 1]++;
            }
        }

        if (strlen(buf1) > strlen(buf2)) {
            i = strlen(buf1);
        }
        else {
            i = strlen(buf2);
        }

        if (array[i] == 0) {
            i--;
        }

        for (i; i >= 0; i--) {
            printf("%c", array[i] + 0x30);
        }
        printf("\n");
    }

    return 0;
}