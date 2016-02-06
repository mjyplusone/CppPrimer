#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find_if;
using std::bind;

inline bool check_size(const string& s, string::size_type sz)
{
	return s.size() < sz;
}

inline vector<int>::const_iterator find_first_bigger(const vector<int>& v,const string& s)
{
	return find_if(v.cbegin(), v.cend(),bind(check_size, s, std::placeholders::_1));
}

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };
	string s("test");
	cout << *find_first_bigger(v, s) << endl;
	  
	return 0;
}
