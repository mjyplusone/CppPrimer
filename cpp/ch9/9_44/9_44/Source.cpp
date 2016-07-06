#include <iostream>
#include <vector>
#include <string>

using namespace std;

void my_replace(string &s, const string &oldVal, const string &newVal)
{
	int p = 0;
	while ((p = s.find(oldVal, p)) != string::npos)   //string::npos√ª”–∆•≈‰
	{
		s.replace(p, oldVal.size(), newVal);
		p += newVal.size();
	}		
}

int main()
{
	string s = "aaa bbb ccc";
	my_replace(s, "bbb", "ccc");
	cout << s << endl;
	
	return 0;
}