#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s[21];
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (s[i][j] == '*') {
				if (j + 4 < n && s[i][j + 1] == '*' && s[i][j + 2] == '*'
					&& s[i][j + 3] == '*' && s[i][j + 4] == '*')
				{
					printf("Win %d %d", j, i);	//注意根据样例2，应该是先列后行 
					return 0;
				}
				//打竖判断
				if (i + 4 < n && s[i + 1][j] == '*' && s[i + 2][j] == '*'
					&& s[i + 3][j] == '*' && s[i + 4][j] == '*')
				{
					printf("Win %d %d", j, i);
					return 0;
				}

				//斜右下判断
				if (i + 4 < n && j + 4 < n && s[i + 1][j + 1] == '*' && s[i + 2][j + 2] == '*'
					&& s[i + 3][j + 3] == '*' && s[i + 4][j + 4] == '*')
				{
					printf("Win %d %d", j, i);
					return 0;
				}

				//斜左下判断
				if (i + 4 < n && j - 4 < n && s[i + 1][j - 1] == '*' && s[i + 2][j - 2] == '*'
					&& s[i + 3][j - 3] == '*' && s[i + 4][j - 4] == '*')
				{
					printf("Win %d %d", j - 4, i + 4);	//因为是斜左下，所以最左边第一颗棋子应该是最下面的一颗 
					return 0;
				}
			}
		}
	}
	printf("Not yet");
}