#include <iostream>
#include <string>
#include <vector>

using namespace std;

//用一个整形数组初始化一个vector对象
int main()
{
	int arry[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> ivec(begin(arry), end(arry));
	for (auto &c : ivec)
		cout << c << " ";
	cout << endl;
	
	return 0;
}