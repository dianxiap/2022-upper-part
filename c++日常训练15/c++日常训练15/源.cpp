#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2, s3;
    char c;
    while (cin >> c, c != ',')s1 += c;
    while (cin >> c, c != ',')s2 += c;
    while (cin >> c)s3 += c;
    if (s1.size() < s2.size() || s1.size() < s3.size())cout << -1;
    else {

        int l = 0;
        while (l <= s1.size()) {       //��������s1
            int k = 0;
            while (k <= s2.size()) {      //��������s2
                if (s1[l + k] != s2[k])break;    //s2����s1���ִ�
                k++;
            }
            if (k == s2.size())break;   //�ҵ�����ǰ���s1���ִ�s2
            l++;
        }
        int r = s1.size() - s3.size();   //
        while (r >= 0) {
            int k = 0;
            while (k < s3.size()) {
                if (s1[r + k] != s3[k])break;
                k++;
            }
            if (k == s3.size())break;
            r--;                //��ͷ��ʼ������
        }

        l = l + s2.size() - 1;
        if (l >= r)cout << -1;
        else cout << r - l - 1;



    }
}