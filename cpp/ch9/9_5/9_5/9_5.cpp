#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator find(vector<int>::iterator begin, vector<int>::iterator end, int val)
{
	while (begin != end)
	{
		if (*begin == val)
			return begin;
		begin++;
	}
	return end;
}

int main()
{
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << find(ivec.begin(), ivec.end(), 7) - ivec.begin() << endl;


	return 0;
}