#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int i, j;
    int a = 1, b = 1, d = 0, e = 0;//a�����˷��ڣ�b����������
    char  c[71];
    for (i = 0; i < 71; i++) {
        e++;
        scanf("%c", &c[i]);
        if (c[i] == '$') {
            break;
        }
        if (a == 2 || b == 1) {   //a=2��ʾ�����˷��ڣ�b=1��ʾ�����ڽ���
            if (e == 3 && a == 2) {
                a = 1;
                e = 0;
            }  //e=3��ʾ3����˷��ڽ���
            if (c[i] == 'T') { //ץ������������������
                b = -2;
                printf("D");
                d = d + 7;
            }
            else if (c[i] == 'X') {
                b = -1;
                printf("U");
            }
            else if (c[i] == 'C') {//���˷�����
                a = 2;
                b = 1;     //��������
                d -= 3;
                printf("!");
                e = 1;   //��ʾ�˺�2��3�춼���ɳ�����
            }

        }
        else printf("-");//���ɳ�����
        b++;
    }
    printf("\n%d", d);
}