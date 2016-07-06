#include <iostream>
#include <string>

using namespace std;

//·¶Î§forÓï¾äµÄÊ¹ÓÃ
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