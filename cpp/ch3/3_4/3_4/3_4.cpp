#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*�Ƚ��ַ����Ƿ���ȣ�����ϴ��
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

	//�Ƚ������ַ����Ƿ�ȳ����������
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