#include <iostream>

using namespace std;

int main()
{
	auto sum = [](int a, int b){return a + b; };
	cout << sum(1, 2) << endl;
	
	
	return 0;
}