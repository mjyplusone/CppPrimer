#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

inline void output(list<string> &words)
{
	for (auto iter = words.begin(); iter != words.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void elimDups(list<string> &words)
{
	output(words);

	words.sort();
	output(words);

	words.unique();
	output(words);
}

int main()
{
	list<string> slist{ "aaa", "bbb", "ccc", "bbb" };
	elimDups(slist);


	return 0;
}