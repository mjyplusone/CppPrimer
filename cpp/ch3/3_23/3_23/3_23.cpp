#include <iostream>
#include <string>
#include <vector>

using namespace std;
//������10��Ԫ�ص�vector��Ȼ���õ�������ÿ��Ԫ�ر�Ϊԭ����2��
int main()
{
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		*iter *= 2;
		cout << *iter << " ";
	}
	cout << endl;
	
	return 0;
}