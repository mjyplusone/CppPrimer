#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> ivec;
	list<int> ilist;

	ivec.assign(ia, ia + 11);
	ilist.assign(ia, ia + 11);
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	for (list<int>::iterator iter2 = ilist.begin(); iter2 != ilist.end(); iter2++)
		cout << *iter2 << " ";
	cout << endl;

	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); )
	{
		if (*iter % 2 == 0)
		{
			iter = ivec.erase(iter);
		}	
		else iter++;
	}
	
	
	for (list<int>::iterator iter2 = ilist.begin(); iter2 != ilist.end(); )
	{
		if (*iter2 % 2 != 0)
		{
			iter2 = ilist.erase(iter2);
		}
		else iter2++;
	}
	
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	
	
	for (list<int>::iterator iter2 = ilist.begin(); iter2 != ilist.end(); iter2++)
		cout << *iter2 << " ";
	cout << endl;
	
	
	
	return 0;
}