#include <bits/stdc++.h>
using namespace std;
stack<char>q;
int main()
{
	string s;
	char a;
	cin>>s;
	for(int i=0;i<s.size();i)
	{
		if(s[i]<'a'||s[i]>'z')
		{
			if(s[i]<'A'||s[i]>'Z')
			{
				if(s[i]!='('&&s[i]!=')')
				i++;
			}
		}
		if(s[i]=='A')
		{
			cout<<"sae";
			i++;
		}
		if(s[i]=='B')
		{
			cout<<"tsaedsae";
			i++;
		}
		if(s[i]==')')
		continue;
		if(s[i]=='(')
		{
			i++;
			if(s[i]==')')
			{
			 i++;
			 continue;
		    }
		    a=s[i];
		    i++;
			while(s[i]!=')')
			{
				q.push(s[i]);
				i++;
			}
			while(q.size()!=0)
			{
				cout<<a<<q.top();
				q.pop();
			}
			cout<<a;
			i++;
		}
	}
	return 0;
}
