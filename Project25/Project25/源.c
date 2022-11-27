#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* dest, char* src)
{
    assert(dest != NULL); // 断言   "dest不能等于NULL"
    assert(src != NULL);  // 断言   "src 不能等于NULL"

    while (*dest++ = *src++)
        ;
}

int main()
{
    char arr1[20] = "xxxxxxxxxx";
    char arr2[] = "hello";
    my_strcpy(arr1, NULL); // 👈 实验：传入一个NULL
    printf("%s\n", arr1);

    return 0;
}