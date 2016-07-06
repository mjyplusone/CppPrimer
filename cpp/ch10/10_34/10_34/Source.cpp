#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7 };
	vector<int>::reverse_iterator iter;
	for (iter = ivec.rbegin(); iter != ivec.rend(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;


	return 0;
}