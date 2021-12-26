#include<bits/stdc++.h>
using namespace std;
stack<char>match;
bool check(string s,int n)
{
	for(int i=0;i<n;i++)
	{
			if(s[i]=='('||s[i]=='['||s[i]=='{')
			{
				match.push(s[i]);
			}
			else if(s[i]==')')
			{
				if(!match.empty()&&match.top()=='(')//匹配成功
				{
					match.pop();
				}
				else return 0;
			}
			else if(s[i]==']')
			{
				if(!match.empty()&&match.top()=='[')//匹配成功
				{
					match.pop();
				}
				else return 0;
			}
			else if(s[i]=='}')
			{
				if(!match.empty()&&match.top()=='{')//匹配成功
				{
					match.pop();
				}
				else return 0;
			}
	}
	if(match.empty()) return 1;
	else return 0;
}
int main()
{
	string s;
	getline(cin,s);
	int n=s.size();
	if(check(s,n))cout<<"yes";
	else cout<<"no";
	return 0;
}