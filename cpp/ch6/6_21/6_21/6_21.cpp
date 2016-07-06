#include <iostream>
#include <string>

using namespace std;

int cmp(const int cnt1, const int *cnt2)
{
	if (cnt1 >= *cnt2)
		return cnt1;
	else
		return *cnt2;
}

int main()
{
	cout << "Enter a number: " << endl;
	int num1;
	cin >> num1;
	int num[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "The max is: " << cmp(num1, num) << endl;
	
	return 0;
}