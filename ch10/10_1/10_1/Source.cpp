#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

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

	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Enter a number: " << endl;
	cin >> val;
	cout << "��" << count(ivec.begin(), ivec.end(), val) << "��" << val;

	
	
	return 0;
}