#include <bits/stdc++.h>
using namespace std;
stack<char>a;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{')
		{
			a.push(s[i]);
		}
		if(s[i]==')')
		{
			if(a.top()=='(')
			a.pop();
		}
		if(s[i]==']')
		{
			if(a.top()=='[')
			a.pop();
		}
		if(s[i]=='}')
		{
			if(a.top()=='{')
			a.pop();
		}
	}
	if(a.size()==0)
	{
		cout<<"yes";
	}
	else cout<<"no";
	return 0;
}
