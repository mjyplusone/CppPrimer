#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> ifl{ 1, 2, 3, 4, 5, 6, 7 };
	auto pre = ifl.before_begin();
	auto curr = ifl.begin();
	while (curr != ifl.end())
	{
		if (*curr % 2 != 0)
			curr = ifl.erase_after(pre);
		else
		{
			pre = curr;
			curr++;
		}
	}

	for (curr = ifl.begin(); curr != ifl.end(); curr++)
		cout << *curr << " ";
	cout << endl;
	
	return 0;
}