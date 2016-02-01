#include <iostream>
#include <vector>
#include <list>

using namespace std;

//list<int> ≥ı ºªØ vector<double>
int main()
{
	list<int> ilist{ 1, 2, 3, 4, 5, 6, 7 };
	vector<int> ivec{ 2, 3, 4, 5, 6, 7, 8 };

	vector<double> dvec1(ilist.begin(), ilist.end());
	vector<double> dvec2(ivec.begin(), ivec.end());
	
	for (vector<double>::iterator iter = dvec1.begin(); iter != dvec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	for (vector<double>::iterator iter = dvec2.begin(); iter != dvec2.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	
	return 0;
}