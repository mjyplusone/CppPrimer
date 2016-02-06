#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline void output(vector<string> &words)
{
	for (auto iter = words.begin(); iter != words.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;//make_plural(wc, "word ", "s ")当输入中文本中
	//word数大于一是在word后加s，为words为word的复数！
}

void biggies(vector<string> &words, vector<string>::size_type i)
{
	output(words);

	auto num = count_if(words.begin(), words.end(), [i](const string &a){return a.size() >= i; });
	cout << num << " " << make_plural(num, "word", "s") << " of length " << i << " or longer" << endl;
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

	biggies(svec, 5);
	
	
	return 0;
}