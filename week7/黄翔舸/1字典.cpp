#include<iostream>
#include<map>
#include<cstring>
#include<iterator>
using namespace std;
int main()
{
	map<string, string>zd;
	map<string, string>::iterator iter;
	string s1, s2, s3;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		zd[s2] = s1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s3;
		iter = zd.find(s3);
		if (iter != zd.end())
		{
			cout << zd[s3] << endl;
		}
		else
		{
			cout << "eh" << endl;
		}
	}
	





	return 0;
}