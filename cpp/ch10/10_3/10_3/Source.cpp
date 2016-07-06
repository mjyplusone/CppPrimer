#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

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

	cout << "The sum is: " << accumulate(ivec.begin(), ivec.end(), 0) << endl;
	
	
	return 0;
}