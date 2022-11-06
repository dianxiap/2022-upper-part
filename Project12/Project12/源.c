#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//一个可能的函数被调用进行测试的例子像这样：
//** 注意： 实际的测试程序可能与下面这个程序很不同！

int strNcpy(char* dest, const char* src, int n);
int main() {
    char dest[10];
    char* src = "helloop";
    int flag;
    flag = strNcpy(dest, src, 7);
    printf("%d: %s\n", flag, dest);
    return 0;
}
/*  您的代码将被嵌在此处 */
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

int strNcpy(char* dest, const char* src, int n) {//注意，与string.h中声明的strncpy( )并不相同
    int i;
    int m = my_strlen(src);
    if (m > n) {

        for (i = 0; i < n - 1; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return 0;
    }
    if (m < n) {

        for (i = 0; i < n - 1; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
    return 1;
    }
    if (m == n)
    {
        for (i = 0; i < n; i++) {
            dest[i] = src[i];
        
        }
        dest[i] = '\0';
        return 1;
    }

}