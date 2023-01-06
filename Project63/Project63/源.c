#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

struct Stu
{
    char name[20];
    int age;
};

/*
void qsort (
    void* base,
    size_t num,
    size_t size,
    int (*cmp_int)(const void* e1, const void* e2)
    );
*/

int cmp_struct_age(const void* e1, const void* e2)
{
    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_struct_name(const void* e1, const void* e2)
{
    return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

void struct_sort()
{
    // 使用qsort函数排序结构体数据
    struct Stu s[3] = {
        {"Ashe", 39},
        {"Hanzo", 38},
        {"Ana", 60}
    };
    int sz = sizeof(s) / sizeof(s[0]);
    // 按照年龄排序
    qsort(s, sz, sizeof(s[0]), cmp_struct_age);
    // 按照名字来排序
    qsort(s, sz, sizeof(s[0]), cmp_struct_name);
}

int main()
{
    struct_sort();

    return 0;
}