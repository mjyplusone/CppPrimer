#include <iostream>
#include <string>

using namespace std;

//�ж�string���Ƿ��д�д��ĸ
bool IsUp(const string &str)
{
	for (auto &c : str)
		if (isupper(c))
			return true;
	return false;
}

//�ִ��д�дתСд
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
		cout << "����ת����" << endl;
	
	
	return 0;
}