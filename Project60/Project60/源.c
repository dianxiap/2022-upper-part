#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int arr[10] = { 0 };

    int* p1 = arr;
    int(*p2)[10] = &arr;

    printf("%p\n", p1);
    printf("%p\n", p1 + 1);

    printf("%p\n", p2);
    printf("%p\n", p2 + 1);

    return 0;
}