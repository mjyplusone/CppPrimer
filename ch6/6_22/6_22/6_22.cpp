#include <iostream>

using namespace std;

void swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int main()
{
	int num1 = 1, num2 = 10;
	int *p = &num1, *q = &num2;
	cout << "Before swap: " << "p is " << *p << " and q is " << *q << endl;
	swap(p, q);
	cout << "After swap: " << "p is " << *p << " and q is " << *q << endl;

	return 0;
}