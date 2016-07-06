
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char *word1 = "aaa";
	char *word2 = "bbb";
	char *r = new char[strlen(word1) + strlen(word2) + 1];
	strcpy_s(r, strlen(word1) + 1, word1);
	strcat_s(r, strlen(word1) + strlen(word2) + 1, word2);
	cout << r << endl;
	
	//重写
	string str1 = "aaa";
	string str2 = "bbb";
	strcpy_s(r, str1.size() +str2.size() + 1, (str1 + str2).c_str());
	cout << r << endl;

	delete[]r;

	return 0;
}
