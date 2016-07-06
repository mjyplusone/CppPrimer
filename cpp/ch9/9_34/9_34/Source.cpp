#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7 };
	auto iter = ivec.begin();
	string temp;
	while (iter != ivec.end())
	{
		if (*iter % 2 == 0)
		{
			iter = ivec.insert(iter, *iter);
			iter++; iter++;
		}
		else
			iter++;

		for (auto begin = ivec.begin(); begin != ivec.end(); begin++)
			cout << *begin << " ";
		cout << endl;
		cin >> temp;
	}
	
	
	return 0;
}