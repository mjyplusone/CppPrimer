#include <iostream>

using namespace std;

//��д����f���ĸ��汾��ʹ������һ���������ֵ���Ϣ
void f()
{
	cout << "����Ҫ����" << endl;
}

void f(int)
{
	cout << "һ�����Ͳ���" << endl;
}

void f(int, int)
{
	cout << "�������Ͳ���" << endl;
}

void f(double, double = 3.14)
{
	cout << "����double����" << endl;
}

int main()
{
	f();
	f(1);
	f(1, 1);
	f(1.11, 3.14);


	return 0;
}