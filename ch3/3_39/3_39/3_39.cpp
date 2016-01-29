#include <iostream>
#include <string>

using namespace std;

int main()
{
	//比较两个string
	string str1, str2;
	cout << "Enter 2 strings: " << endl;
	cin >> str1 >> str2;
	if (str1 == str2)
		cout << "Equal" << endl;
	else if (str1 > str2)
		cout << "stirng1>string2" << endl;
	else
		cout << "string2>string1" << endl;
	
	//比较两个C风格字符串
	char str3[20], str4[20];
	cout << "Enter 2 strings: " << endl;
	cin >> str3 >> str4;
	int cmp = strcmp(str3, str4);
	if (cmp==0)
		cout << "Equal" << endl;
	else if (cmp>0)
		cout << "stirng3>string4" << endl;
	else
		cout << "string3>string4" << endl;


	return 0;
}