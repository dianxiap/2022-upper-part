#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#define SIZE 20
int main()
{
    int num[SIZE], double_num[SIZE], bit = 0; //bit��¼ԭʼ��λ��
    int digit[10] = { 0,0,0,0,0,0,0,0,0,0 }; //digit[i]����������n������i���ֵĴ���
    int flag = 1; //flagΪ1ʱ�����yes,Ϊ0ʱ�����no
    char temp;
    temp = getchar();
    while (temp >= '0' && temp <= '9') {  //����ԭʼ��
        num[bit] = temp - '0';
        digit[num[bit]]++;  //��¼ԭʼ��ÿ�����ֳ��ֵĴ���
        bit++;
        temp = getchar();
    }
    for (int i = bit - 1; i >= 0; i--) {     //ԭʼ��ÿλ����2�õ�������
        double_num[i] = num[i] * 2;
    }
    //�����λ��double_num[0]������λ������>10�����ж�flagΪ0
    for (int i = bit - 1; i > 0; i--) {
        if (double_num[i] / 10 != 0) {
            double_num[i] = double_num[i] % 10;
            double_num[i - 1] += 1;
        }
        digit[double_num[i]]--;
    }
    //�ж�ԭʼ��double���Ƿ�λ����֮ǰ��ͬ������ͬ��flagΪ0
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
    //������
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
