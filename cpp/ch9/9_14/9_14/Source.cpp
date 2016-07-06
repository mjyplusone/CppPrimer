#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
	list<char*> clist{ "aaa", "bbb", "ccc" };
	vector<string> svec(clist.begin(), clist.end());
	
	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}