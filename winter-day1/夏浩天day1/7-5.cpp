#include<iostream>
#include<stack>
#include<string.h>
#include<fstream>
#include<string>
using namespace std;
int q, p;//q(   p)
int main()
{
	
	string lsz; 
	while (cin >> lsz)
	{
		q = 0; p = 0;
		for (int i = 0; i < lsz.size(); i++)
		{
			if (lsz[i] == ')')
			{
				if (!q) p++;
				else q--;
			}
			else
				q++;
		}
		if (!p && !q) cout << "Match";
		else
		{
			cout << p + q << endl;
			while (p > 0) 
			{
				cout << '('; p--;
			}
            cout << lsz;
			while (q > 0) 
			{ 
				cout << ')'; 
				q--; 
			}
		}
		cout << endl;
	}
}