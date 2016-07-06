#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> build()
{
	return make_shared<vector<int>>();
}

void send(shared_ptr<vector<int>> p)
{
	int val;
	while (cin >> val)
		p->push_back(val);
}

void output(shared_ptr<vector<int>> p)
{
	for (const auto &c : *p)
		cout << c << " ";
	cout << endl;
}

int main()
{
	shared_ptr<vector<int>> p = build();
	send(p);
	output(p);


	return 0;
}