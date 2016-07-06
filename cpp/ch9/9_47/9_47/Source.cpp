#include <iostream>
#include <string>

using namespace std;

void find(string &s, const string &word)
{
	int p = 0;
	while ((p = s.find_first_of(word, p)) != string::npos)
	{
		cout << "pos: " << p << " word: " << s[p] << endl;
		p++;
	}
}

void find2(string &s, const string &word)
{
	int p = 0;
	while ((p = s.find_first_not_of(word, p)) != string::npos)
	{
		cout << "pos: " << p << " word: " << s[p] << endl;
		p++;
	}
}

int main()
{
	string s = "ab2c3d7R4E6";
	cout << "numbers:" << endl;
	find(s, "0123456789");
	cout << "character: " << endl;
	find(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	cout << "numbers:" << endl;
	find2(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	cout << "character: " << endl;
	find2(s, "0123456789");
	
	
	return 0;
}