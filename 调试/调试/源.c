#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//һ�����ܵĺ��������ý��в��Ե�������������
//** ע�⣺ ʵ�ʵĲ��Գ�������������������ܲ�ͬ��

int strNcpy(char* dest, const char* src, int n);
int main() {
    char dest[10];
    char* src = "hello";
    int flag;
    flag = strNcpy(dest, src, 7);
    printf("%d: %s\n", flag, dest);
    return 0;
}
/*  ���Ĵ��뽫��Ƕ�ڴ˴� */
int my_strlen(char* str)
{
    int count = 0;
    while ('\0' != *str)
    {
        count++;
        str++;
    }
    return count;
}


int strNcpy(char* dest, const char* src, int n) {//ע�⣬��string.h��������strncpy( )������ͬ
    int i;
    int m = my_strlen(src);
    if (m+1 > n) {

        for (i = 0; i < n - 1; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return 0;
    }
    else if (m+1 <n) {

        for (i = 0; i < n; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return 1;
    }
    else if (m + 1 == n)
    {
        for (i = 0;i < n;i++)
        {
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return 1;
    }
  

}