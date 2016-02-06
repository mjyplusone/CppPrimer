#include <iostream>
#include <vector>

using namespace std;

vector<int>* build()
{
	vector<int> *p = new vector<int>();
	return p;
}

void send(vector<int> *p)
{
	int val;
	while (cin >> val)
		p->push_back(val);
}

void output(vector<int> *p)
{
	for (const auto &c : *p)
		cout << c << " ";
	cout << endl;
}

int main()
{
	vector<int> *p = build();
	send(p);
	output(p);
	delete p;


	return 0;
}