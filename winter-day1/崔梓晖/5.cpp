#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int t=0,n=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')
			{
				t++;
			}
			else if(s[i]==')')
			{
				if(t!=0)
				{
					t--;
				}
				else n++;
			}
		}
		if(t==0&&n==0)
		{
			cout<<"Match"<<endl;
			continue;
		}
		else 
		{
			cout<<t+n<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<'(';
			}
			cout<<s;
			for(int i=1;i<=t;i++)
			{
				cout<<')';
			}
			cout<<endl;
		}
	}
	return 0;
}

