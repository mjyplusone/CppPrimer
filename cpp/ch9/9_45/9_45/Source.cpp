#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addname(string &name, const string &pre, const string &behind)
{
	name.insert(name.begin(), 1, ' ');
	name.insert(name.begin(), pre.begin(), pre.end());
	name.append(" ");
	name.append(behind.begin(), behind.end());
}

int main()
{
	string s = "aaa";
	addname(s, "bbb", "ccc");
	cout << s << endl;
	
	
	return 0;
}