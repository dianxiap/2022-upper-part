#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 100010;

int main()
{
	string s[N];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> s[i];
	for (int i = 0; i < n; i++)
	{
		int temp = 1;
		for (int j = i+1; j < n; j++)
		{
			if (s[i] == s[j])temp = 0;
		}
		if (temp)cout << s[i] << endl;
	}
}