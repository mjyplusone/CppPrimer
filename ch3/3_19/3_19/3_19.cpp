#include <iostream>
#include <string>
#include <vector>

using namespace std;

//���庬��10��Ԫ�ص�vector��������Ԫ�ض���42�������ַ���
int main()
{
	//����1
	vector<int> ivec1;
	for (int i = 0; i < 10; i++)
		ivec1.push_back(42);
	
	//����2
	vector<int> ivec2(10, 42);

	//����3
	vector<int> ivec3{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };

	//����4
	vector<int> ivec4(10);
	for (auto &c : ivec4)
		c = 42;

	return 0;
}