#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int e[N]; //存储数值
int l[N]; //左指针
int r[N]; //右指针
int idx;  //数组下标的索引值

//功能：初始化
void init() {
    r[0] = 1, l[1] = 0, idx = 2;//0的右侧是1，1的左侧是0,0：头，1：尾，正式数据索引从2开始
}

/**
 * 功能：在下标为k的结点后面插入数字x
 * @param k 在下标为k的结点后面
 * @param x 插入数字x
 */
void add(int k, int x) {
    e[idx] = x, r[idx] = r[k], l[idx] = k, l[r[k]] = idx, r[k] = idx++;
}

/**
 * 功能：将下标为k的结点删除
 * @param k
 */
void remove(int k) {
    //干掉两条边
    r[l[k]] = r[k], l[r[k]] = l[k];
}

int main() {
    //优化输入
    ios::sync_with_stdio(false);
    //初始化
    init();
    int m, k, x;
    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        if (op == "L") {
            cin >> x;
            //最左端插入数x
            //最左端就是表示在0的右侧插入一个数据
            add(0, x);
        }
        else if (op == "R") {
            cin >> x;
            //最右端插入数x
            add(l[1], x);//1号端点的左侧，就是最右端
        }
        else if (op == "D") {
            cin >> k;
            remove(k + 1); //idx从2开始，所以下标需要k+1传入才对
        }
        else if (op == "IL") {
            cin >> k >> x;
            add(l[k + 1], x); //在这个k的左侧那个元素的右侧插入数据x
        }
        else if (op == "IR") {
            cin >> k >> x;
            add(k + 1, x);  //正常调用
        }
    }
    //注意双链表的输出方法,0和1是一头一尾，idx从2开始，换言之，从r[0]就是开始进行遍历，出现1就结尾了
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
    cout << endl;
    return 0;
}
