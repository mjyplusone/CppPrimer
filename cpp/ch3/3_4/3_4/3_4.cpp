#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*比较字符串是否相等，输出较大的
	string str1, str2;
	cout << "Enter 2 strings: " << endl;
	while (cin >> str1 >> str2)
	{
		if (str1 == str2)
			cout << "Equal" << endl;
		else if (str1 > str2)
			cout << str1 << " is bigger" << endl;
		else
			cout << str2 << " is bigger" << endl;
	}
	*/

	//比较输入字符串是否等长，输出长的
	string str1, str2;
	cout << "Enter 2 strings: " << endl;
	while (cin >> str1 >> str2)
	{
		auto len1 = str1.size();
		auto len2 = str2.size();
		if (len1 == len2)
			cout << "Equal" << endl;
		else if (len1 > len2)
			cout << str1 << " is longer" << endl;
		else
			cout << str2 << " is longer" << endl;
	}
	

	return 0;
}