#include <iostream>
#include <vector>
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
	
	vector<int> ivec;
	int val;
	while (file >> val)
	{
		ivec.push_back(val);
	}
	
	fill_n(ivec.begin(), ivec.size(), 0);
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	
	
	
	return 0;
}