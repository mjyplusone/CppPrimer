#include <iostream>
#include <string>
#include <vector>

using namespace std;
//创建有10个元素的vector，然后用迭代器把每个元素变为原来的2倍
int main()
{
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		*iter *= 2;
		cout << *iter << " ";
	}
	cout << endl;
	
	return 0;
}