#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    char a;
    scanf("%c", &a);//输入一个任意字符
    int i = 1;//记行数用的
    int j, g; //j是输出“空格”用的，g是输出“字符+空格”用的
    for (i = 1; i < 6; i++)//关于行数i在前5行执行的循环（包括第5行）
    {
        for (j = 5 - i; j > 0; j--)//输出第n行的前5-n个空格（n<=5）
        {
            printf(" ");
        }
        for (g = 0; g < i; g++)//输出第n行的所有空格后的字符
        {
            printf("%c ", a);//注意所输出的%c后有一个空格
        }
        printf("\n");//第n行输出结束，执行换行操作
    }//运行到这里就输出了n行的字符金字塔图形
    return 0;
}