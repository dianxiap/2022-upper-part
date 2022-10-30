#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

//int main() {
//	int b[26] = { 0 };  //桶排序
//	char a[100];
//	cin >> a;
//
//	for (int i = 0; a[i]; i++) {
//		b[a[i] - 'a']++;
//	}
//	for(int i=0;a[i];i++){
//		if (b[a[i] - 'a']==1) {
//			cout << a[i] << endl;
//			return 0;
//		}
//	}
//
//}
//int main() {
//	char a[31];
//	cin >> a;
//	char c='0';
//	cin >> c;
//	for (int i = 0; a[i]; i++) {
//		if (a[i] == c) {
//			a[i] = '#';
//		}
//	}
//	puts(a);
//}

int main() {
	//string s1;   //默认的空字符串
	//string s2 = s1;  //s2是s1的副本
	//string s3 = "hiya";
	//string s4(10, 'c');  //s4的内容10个c
	//cin >> s1 >>s2;
	//getline(cin, s1);
	//
	//string s1;
	//string s2;
	//cin >> s1;
	//cout << s1.empty() << endl;   //判断字符串是不是空的，空1非空0
	//cout << s2.empty() << endl;
	//string s1, s2;
	//cin >> s1;
	//cin >> s2;
	//string s3 = s1 + s2;
	//cout << s3 << endl;

	/*string s = "4456wafhhl World!";
	for (char c : s) {
		
		
		cout << c << endl;
	}*/
	
	string s;
	getline(cin, s);
	for (char& c : s) {
		if (c >= 'a' && c <= 'z')c = (c - 'a' + 1) % 26 + 'a';
		else if (c >= 'A' && c <= 'Z')c = (c - 'A' + 1) % 26 + 'A';
	}
	cout << s << endl;


}