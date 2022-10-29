#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#define SIZE 20
int main()
{
    int num[SIZE], double_num[SIZE], bit = 0; //bit记录原始数位数
    int digit[10] = { 0,0,0,0,0,0,0,0,0,0 }; //digit[i]代表输入数n中数字i出现的次数
    int flag = 1; //flag为1时，输出yes,为0时，输出no
    char temp;
    temp = getchar();
    while (temp >= '0' && temp <= '9') {  //输入原始数
        num[bit] = temp - '0';
        digit[num[bit]]++;  //记录原始数每个数字出现的次数
        bit++;
        temp = getchar();
    }
    for (int i = bit - 1; i >= 0; i--) {     //原始数每位乘以2得到新数组
        double_num[i] = num[i] * 2;
    }
    //处理进位，double_num[0]不做进位处理，若>10，则判断flag为0
    for (int i = bit - 1; i > 0; i--) {
        if (double_num[i] / 10 != 0) {
            double_num[i] = double_num[i] % 10;
            double_num[i - 1] += 1;
        }
        digit[double_num[i]]--;
    }
    //判断原始数double后，是否位数与之前相同，若不同则flag为0
    if (double_num[0] / 10 != 0) {
        flag = 0;
    }
    else {
        digit[double_num[0]]--;
        for (int j = 0; j < 10; j++) {
            if (digit[j] != 0) {
                flag = 0;
                break;
            }
        }
    }
    //输出结果
    if (flag == 0) {
        printf("No\n");
    }
    else {
        printf("Yes\n");
    }
    for (int i = 0; i < bit; i++) {
        printf("%d", double_num[i]);
    }
    return 0;
}
