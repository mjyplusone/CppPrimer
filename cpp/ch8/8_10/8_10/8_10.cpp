#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream file("1.txt");
	if (!file)
	{
		cerr << "Error!" << endl;
		return -1;
	}

	string line;
	vector<string> svec;
	while (getline(file, line))
	{
		svec.push_back(line);
	}
	file.close();

	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++)
	{
		istringstream line2(*iter);
		string word;
		while (line2 >> word)
			cout << word << " ";
		cout << endl;
	}
	
	
	return 0;
}