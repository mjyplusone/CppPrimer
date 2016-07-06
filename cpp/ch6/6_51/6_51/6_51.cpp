#include <iostream>

using namespace std;

//编写函数f的四个版本，使其各输出一条可以区分的消息
void f()
{
	cout << "不需要参数" << endl;
}

void f(int)
{
	cout << "一个整型参数" << endl;
}

void f(int, int)
{
	cout << "两个整型参数" << endl;
}

void f(double, double = 3.14)
{
	cout << "两个double类型" << endl;
}

int main()
{
	f();
	f(1);
	f(1, 1);
	f(1.11, 3.14);


	return 0;
}