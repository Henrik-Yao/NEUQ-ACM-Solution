#include <bits/stdc++.h>
using namespace std;
string s1;
int main()
{
	while (getline(cin,s1))
	{
		int t1 = 0,t2 = 0;
		stack <int> s;
		for (int i = 0;i < s1.size(); i++)
		{
			if (s1[i] == '(')
			{
				s.push('(');
			} else {
				if (!s.empty())
				{
					s.pop();
				} else {
					t1++;
				}
			}
		}
		if (s.empty() && t1 == 0) 
		{
			cout << "Match" << endl;
			continue;
		}
		while (!s.empty())
		{
			s.pop();
			t2++;
		}
		cout << t1 + t2 << endl;
		for (int i = 1;i <= t1; i++)
		{
			cout << "(";
		}
		cout << s1;
		for (int i = 1;i <= t2; i++)
		{
			cout << ")";
		}
		cout << endl;
	}
	return 0;
}
