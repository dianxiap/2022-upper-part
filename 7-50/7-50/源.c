#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int n, m, flag = 0;
int x1, y1, x2, y2;
char ch[7] = { '1','D','S','W','Y','B','S' };
char s[20][20];
void dfs(int x, int y, int step) {
    int tx, ty;
    int next[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1} };
    if (step == 6) {
        x2 = x;
        y2 = y;
        flag = 1;
        return;
    }
    for (int i = 0; i < 8; i++) {
        tx = x + next[i][0];
        ty = y + next[i][1];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && s[tx][ty] == ch[step + 1]) {
            dfs(tx, ty, step + 1);
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", &s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (s[i][k] == 'D')
                dfs(i, k, 1);
            if (flag) {
                x1 = i;
                y1 = k;
                break;
            }
        }
        if (flag)break;
    }
    if (flag) {
        printf("%d %d\n%d %d\n%d", x1, y1, x2, y2, x1 + y1 + x2 + y2);
    }
    else printf("DSWYBS");
    return 0;
}

//此题再学习算法后再重做一遍。