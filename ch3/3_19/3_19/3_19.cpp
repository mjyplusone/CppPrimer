#include <iostream>
#include <string>
#include <vector>

using namespace std;

//定义含有10个元素的vector对象，所有元素都是42，用三种方法
int main()
{
	//方法1
	vector<int> ivec1;
	for (int i = 0; i < 10; i++)
		ivec1.push_back(42);
	
	//方法2
	vector<int> ivec2(10, 42);

	//方法3
	vector<int> ivec3{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };

	//方法4
	vector<int> ivec4(10);
	for (auto &c : ivec4)
		c = 42;

	return 0;
}