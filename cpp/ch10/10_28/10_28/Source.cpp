#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7 };
	list<int> ilist1, ilist2, ilist3,ilist4;
	unique_copy(ivec.begin(), ivec.end(), inserter(ilist1, ilist1.begin()));
	unique_copy(ivec.begin(), ivec.end(), inserter(ilist4, ilist4.end()));
	unique_copy(ivec.begin(), ivec.end(), back_inserter(ilist2));
	unique_copy(ivec.begin(), ivec.end(), front_inserter(ilist3));

	for (auto &c : ilist1)
		cout << c << " ";
	cout << endl;

	for (auto &c : ilist2)
		cout << c << " ";
	cout << endl;

	for (auto &c : ilist3)
		cout << c << " ";
	cout << endl;

	for (auto &c : ilist4)
		cout << c << " ";
	cout << endl;

	return 0;
}
