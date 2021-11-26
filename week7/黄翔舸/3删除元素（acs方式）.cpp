#include<iostream>
#include<cstring>
#include<string>
#include<map>
using namespace std;

int main()
{
	int a[256];
	string s1, s2;
	while (getline(cin, s1)&&getline(cin, s2))
	{


		for (int i = 0; i < 256; i++)
		{
			a[i] = 0;
		}

		
		
		int n = s1.length();
		int m = s2.length();
		for (int i = 0; i < m; i++)
		{
			int temp = s2[i];
			a[temp] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			int temp2 = s1[i];
			if (a[temp2] == 0)
			{
				cout << s1[i];
			}
		}
		cout << endl;
	}
	return 0;
}