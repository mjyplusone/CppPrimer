#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec1{ 1, 2, 3, 4, 5, 6, 7 };
	vector<int> ivec2{ 1, 2, 3, 4, 5, 6, 7 };
	vector<int> ivec3{ 1, 2, 3, 4, 5 };

	cout << (ivec1 == ivec2) << endl;
	cout << (ivec1 == ivec3) << endl;

	return 0;
}