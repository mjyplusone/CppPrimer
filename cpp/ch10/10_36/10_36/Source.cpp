#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> ilist{ 1, 2, 0, 3, 4, 5, 0, 6, 7 };
	auto zero = find(ilist.crbegin(), ilist.crend(), 0);
	zero++;             //ע��zero��zero.base()��ָ��ͬһ��Ԫ��
	int count = 1;
	for (list<int>::iterator iter = ilist.begin(); iter != zero.base(); iter++)
	{
		count++;
	}
	if (count > ilist.size())   cout << "No 0!" << endl;
	else
		cout << count << endl;

	return 0;
}