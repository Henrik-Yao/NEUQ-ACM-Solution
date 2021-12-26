#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	while(cin >> a)
	{
//		for(int i = a.length()-1; i > 0; i--) cout << a[i];
//		cout << endl;
		bool ju = 1;
		stack<char>l,r;
		for(int i = 0; i < a.length(); i++)
		{
			if(a[i] == '(') l.push(a[i]);
			else 
			{
				if(!l.empty()) 
				{
					l.pop();continue;
				}
				else 
				{
					ju = 0;
				}
			}
		}
		for(int i = a.length()-1; i >= 0; i--)
		{
			if(a[i] == ')') r.push(a[i]);
			else 
			{
				if(!r.empty()) 
				{
					r.pop();continue;
				}
				else 
				{
					ju = 0;
				}
			}
		}
		if(ju && l.size()+r.size() == 0) cout << "Match" << endl;
		else 
		{
			cout << l.size() + r.size() << endl;
			for (int i = 1; i <= r.size(); i++) cout << "(";
			cout << a;
			for (int i = 1; i <= l.size(); i++) cout << ")";
			cout << endl;
		}
	}
	
	return 0;
}
