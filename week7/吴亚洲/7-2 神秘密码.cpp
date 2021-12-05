#include<bits/stdc++.h>
using namespace std;
string read()
{
	char x;
	int mul;
	string ans="",s="";
	while(cin>>x)
	{
		if(x=='[')
		{
			cin>>mul;
			s=read();
			while(mul--)
			{
				ans+=s;
			}
		}
		else if(x==']')
		return ans;
		else if(x!='['&&x!=']')
		ans+=x;
	}
}
int main()
{
	cout<<read();
	return 0;
}
