#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    while (cin >> str, str[0] != '.') {
        int len = str.size();
        int n;
        for (n = len; n; n--)
        {
            if (len % n == 0)    //ÿһ���Ӵ��ĳ��ȶ���ĸ����Լ��
            {
                int m = len / n;      //��ִ��ĳ��ȡ����ظ��Ĵ�������ĸ���ĳ���
                string s;
                s = str.substr(0, m);     //�����Ӵ��ó���
                string r;
                for (int i = 0; i < n; i++)r = r + s;
                if (r == str) {               //�жϽ��ִ����Ӻ�����ַ����Ƿ����ԭ�ַ���
                    cout << n << endl;
                    break;
                }
            }
        }
    }
}