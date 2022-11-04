#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

struct p 
{
	int age, heugght;
	double money;
	p(int _age, int height, double _money)
	{
		age = _age;
		heugght = height;
		money = _money;
	}
};
int main() {
	p pe(18, 180, 100);
	cout << pe.age;
}