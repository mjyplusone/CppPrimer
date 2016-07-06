#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	ifstream file1("1.txt");
	if (!file1)
	{
		cout << "file1 Error!" << endl;
		return -1;
	}

	ofstream file2("2.txt");
	if (!file2)
	{
		cout << "file2 Error!" << endl;
		return -1;
	}

	ofstream file3("3.txt");
	if (!file3)
	{
		cout << "file3 Error!" << endl;
		return -1;
	}

	istream_iterator<int> iter1(file1);
	istream_iterator<int> end;
	ostream_iterator<int> iter2(file2, " ");
	ostream_iterator<int> iter3(file3, "\n");
	while (iter1 != end)
	{
		if (*iter1 % 2 != 0)
		{
			*iter2 = *iter1;
			iter2++;
		}
		else
		{
			*iter3 = *iter1;
			iter3++;
		}
		iter1++;
	}


	return 0;
}