#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#define int long long
#define maxn 1000005
using namespace std;



int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}
int pd=0;
string a;
stack<char>s;

signed main()
{
	getline(cin,a);
	int len=a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]=='(') s.push('(');
		else if(a[i]=='[') s.push('[');
		else if(a[i]==']')
		{
			if(s.size()==0) 
			{
				pd=1;break;
			}
			if(s.top()=='[') s.pop();
			else pd=1;
		}
		else if(a[i]==')')
		{
			if(s.size()==0)
			{
				pd=1;break;
			}
			if(s.top()=='(') s.pop();
			else pd=1;
		}
	}
	if(s.size()>0) pd=1;
	if(pd==1) puts("no");
	else puts("yes");
}
