#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream file("1.txt");
	if (!file)
	{
		cout << "Error!" << endl;
		return -1;
	}

	list<string> slist;
	string word;
	while (file >> word)
	{
		slist.push_back(word);
	}

	cout << "Enter a string: " << endl;
	cin >> word;
	cout << "га" << count(slist.begin(), slist.end(), word) << "Иі" << word;
	
	
	return 0;
}