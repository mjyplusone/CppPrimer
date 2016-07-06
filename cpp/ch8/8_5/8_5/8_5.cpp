#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream file("1.txt");
	if (!file)
	{
		cerr << "Error!" << endl;
		return -1;
	}

	string word;
	vector<string> svec;
	while (file >> word)
	{
		svec.push_back(word);
	}
	file.close();

	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++)
	{
		cout << *iter << endl;
	}
	
	
	
	return 0;
}