#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int strNcpy(char* dest, const char* src, int n);
int main() {
    char dest[10];
    char *src= "hello";
    int flag;
    flag = strNcpy(dest, src, 5);
    printf("%d: %s\n", flag, dest);
    return 0;
}
/*  ���Ĵ��뽫��Ƕ�ڴ˴� */
int strNcpy(char* dest, const char* src, int n) {//ע�⣬��string.h��������strncpy( )������ͬ
    int i;
    if (n >= 10) {
        int flag=0;
        if (n == 10) {
            flag = 1;
        }
        else {
            n = 10;
        }
        for (i = 0; i < n - 1; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
        if (flag)return 1;
        else return 0;
    }
    if(n<10) {
        for (i = 0; i<n-1; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return 1;
    }

}