#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

inline void output(vector<string> &words)
{
	for (auto iter = words.begin(); iter != words.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void elimDups(vector<string> &words)
{
	output(words);

	sort(words.begin(), words.end());
	output(words);

	auto end_unique = unique(words.begin(), words.end());
	output(words);

	words.erase(end_unique, words.end());
	output(words);
}

int main()
{
	ifstream file("1.txt");
	if (!file)
	{
		cout << "Error!" << endl;
		return -1;
	}

	vector<string> svec;
	string word;
	while (file >> word)
		svec.push_back(word);
	elimDups(svec);
	
	
	return 0;
}