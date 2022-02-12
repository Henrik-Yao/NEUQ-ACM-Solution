#include <bits/stdc++.h>
using namespace std;

stack <char> zhan;

int main()
{
	string s;
	cin>>s;
	int lens = s.length();
	for (int i=0;i<lens-1;i++)
	{
		if (s[i] == 'A')
            cout << "sae";

		else if (s[i] == 'B')
            cout << "tsaedsae";

		else if (s[i] == '(')
		{
			i++;
			int p=i+1;
			while (s[p]!=')')
			{
				zhan.push(s[p]);
				p++;
			}
			while (zhan.size()>0)
			{
				cout<<s[i]<<zhan.top();
				zhan.pop();
			}
			cout<<s[i];
			i=p;
		}
		else
            cout<<s[i];
	}

	return 0;
}
