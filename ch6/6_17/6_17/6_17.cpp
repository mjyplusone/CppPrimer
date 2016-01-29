#include <iostream>
#include <string>

using namespace std;

//判断string中是否有大写字母
bool IsUp(const string &str)
{
	for (auto &c : str)
		if (isupper(c))
			return true;
	return false;
}

//字串中大写转小写
void trans(string &str)
{
	for (auto &c : str)
		c = tolower(c);
}

int main()
{
	cout << "Enter string: " << endl;
	string str;
	cin >> str;
	if (IsUp(str))
	{
		trans(str);
		cout << "After translate: " << str << endl;
	}
	else
		cout << "不需转换！" << endl;
	
	
	return 0;
}