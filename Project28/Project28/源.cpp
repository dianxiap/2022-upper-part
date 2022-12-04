#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
using namespace std;

const int N = 100010;
string s[N];

int main()
{
	
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		m[s[i]] = false;
	}
	for (int i = 0; i < n; i++)
	{
		if (m[s[i]] == false)
		{
			cout << s[i] << endl;
			m[s[i]] = true;
		}
	}
}
