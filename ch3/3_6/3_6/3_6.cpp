#include <iostream>
#include <string>

using namespace std;

//��Χfor����ʹ��
int main()
{
	string str;
	cout << "Enter a string: " << endl;
	while (cin >> str)
	{
		for (auto &c : str)
			c = 'x';
		cout << str << endl;
	}

	return 0;
}