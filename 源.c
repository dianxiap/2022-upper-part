#define _CRT_SECURE_NO_WARNINGS 1
//7-42
/*皮球从某给定高度自由落下，触地后反弹到原高度的一半，再落下，再反弹，……，如此反复。问皮球在第n次落地时，在空中一共经过多少距离？第n次反弹的高度是多少？

输入格式 :
输入在一行中给出两个非负整数，分别是皮球的初始高度和n，均在长整型范围内。

输出格式 :
在一行中顺序输出皮球第n次落地时在空中经过的距离、以及第n次反弹的高度，其间以一个空格分隔，保留一位小数。题目保证计算结果不超过双精度范围。

输入样例 :
33 5
输出样例 :
94.9 1.0
*/
#include <stdio.h>
int main() {
    long high, n;
    scanf("%ld %ld", &high, &n);
    int i;
    double sum = (double)high;
    double high1;
    double temp = (double)high;
    if (n == 0) {
        printf("0.0 0.0");
    }
    else
    {
        for (i = 0; i < n; i++) {
            high1 = temp / 2;   //每次反弹的高度
            sum += high1 * 2;   //每次反弹后在空中的总长度
            temp = high1;
        }
        printf("%.1f %.1f", sum - 2 * high1, high1);
    }
}