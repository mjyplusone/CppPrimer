#include <iostream>
#include <string>
#include <vector>

using namespace std;
//����vector�������дʱ�Ϊ��д
int main()
{
	vector<string> svec;
	string str;
	cout << "Enter strings: " << endl;
	while (cin >> str)
	{
		svec.push_back(str);
	}
	for (auto &c : svec)
	{
		for (auto &a : c)
			a = towupper(a);
		cout << c << endl;
	}
	
	
	return 0;
}