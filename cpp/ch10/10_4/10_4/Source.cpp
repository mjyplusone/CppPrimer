#include <iostream>
#include <fstream>
#include <vector>
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

	vector<double> dvec;
	double val;
	while (file >> val)
		dvec.push_back(val);

	cout << "The sum is: " << accumulate(dvec.begin(), dvec.end(), 0.0) << endl;
	
	
	return 0;
}