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
					printf("Win %d %d", j, i);	//ע���������2��Ӧ�������к��� 
					return 0;
				}
				//�����ж�
				if (i + 4 < n && s[i + 1][j] == '*' && s[i + 2][j] == '*'
					&& s[i + 3][j] == '*' && s[i + 4][j] == '*')
				{
					printf("Win %d %d", j, i);
					return 0;
				}

				//б�����ж�
				if (i + 4 < n && j + 4 < n && s[i + 1][j + 1] == '*' && s[i + 2][j + 2] == '*'
					&& s[i + 3][j + 3] == '*' && s[i + 4][j + 4] == '*')
				{
					printf("Win %d %d", j, i);
					return 0;
				}

				//б�����ж�
				if (i + 4 < n && j - 4 < n && s[i + 1][j - 1] == '*' && s[i + 2][j - 2] == '*'
					&& s[i + 3][j - 3] == '*' && s[i + 4][j - 4] == '*')
				{
					printf("Win %d %d", j - 4, i + 4);	//��Ϊ��б���£���������ߵ�һ������Ӧ�����������һ�� 
					return 0;
				}
			}
		}
	}
	printf("Not yet");
}