#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int i, j;
    int a = 1, b = 1, d = 0, e = 0;//a代表兴奋期，b代表伤心岂
    char  c[71];
    for (i = 0; i < 71; i++) {
        e++;
        scanf("%c", &c[i]);
        if (c[i] == '$') {
            break;
        }
        if (a == 2 || b == 1) {   //a=2表示处于兴奋期，b=1表示伤心期结束
            if (e == 3 && a == 2) {
                a = 1;
                e = 0;
            }  //e=3表示3天的兴奋期结束
            if (c[i] == 'T') { //抓到老鼠，老鼠伤心两天
                b = -2;
                printf("D");
                d = d + 7;
            }
            else if (c[i] == 'X') {
                b = -1;
                printf("U");
            }
            else if (c[i] == 'C') {//鼠兴奋两天
                a = 2;
                b = 1;     //无伤心气
                d -= 3;
                printf("!");
                e = 1;   //表示此后2，3天都会派出老鼠
            }

        }
        else printf("-");//不派出老鼠
        b++;
    }
    printf("\n%d", d);
}