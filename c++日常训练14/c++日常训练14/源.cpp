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
            if (len % n == 0)    //每一段子串的长度都是母串的约数
            {
                int m = len / n;      //最长字串的长度×其重复的次数等于母串的长度
                string s;
                s = str.substr(0, m);     //将该子串拿出来
                string r;
                for (int i = 0; i < n; i++)r = r + s;
                if (r == str) {               //判断将字串连接后的新字符串是否等于原字符串
                    cout << n << endl;
                    break;
                }
            }
        }
    }
}