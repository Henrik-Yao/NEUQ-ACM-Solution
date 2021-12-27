#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		stack <char> t;
		for(int i=0;i<s.size();i++)
		{
			if(!t.empty()&&t.top()=='('&&s[i]==')')
			{
				t.pop();
			}
			else
			{
				t.push(s[i]);
			}
		}
		int l=0,r=0;
		while(!t.empty())
		{
			if(t.top()=='(')
			{
				r++;
				t.pop();
			}
			else
			{
				l++;
				t.pop();
			}
		}
		if(l+r==0){cout<<"Match"<<endl;}
		else
		{
			cout<<l+r<<endl;
			for(int i=0;i<l;i++)
			{
				cout<<'(';
			}
			cout<<s;
			for(int i=0;i<r;i++)
			{
				cout<<')';
			}
			cout<<endl;
		}
	}
	return 0;
}
