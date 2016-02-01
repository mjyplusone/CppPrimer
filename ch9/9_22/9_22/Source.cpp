#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7 };
	int some_val = 2 ;
	vector<int>::iterator iter = ivec.begin();
	int len = ivec.size(), add = 0;
	while (iter != (ivec.begin() + len / 2 + add))
	{
		if (*iter == some_val)
		{
			iter=ivec.insert(iter, some_val * 2);   //insert后，iter失效，重新赋予
			add++;
			iter++;  iter++;
		}
		else iter++;
	}

	for (iter = ivec.begin(); iter != ivec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	
	return 0;
}