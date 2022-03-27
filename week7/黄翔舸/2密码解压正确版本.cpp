#include<iostream>
#include<cstring>
using namespace std;
string find();
int main()
{
	cout << find();
	return 0;
}
string find()
{
	string sf = "", st;
	int n;
	char ch;
	while (cin >> ch)
	{



		if (ch == '[')
		{
			cin >> n;
			st = find();
			while (n--)
			{
				sf += st;
			}
		}
		else
		{
			if (ch == ']')
			{
				return sf;
			}
			else
			{
				sf += ch;
			}
		}
	}
}