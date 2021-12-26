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
int pd=0,cnt,ans1,ans2;
char c[maxn];
string a;
stack<char>s;

signed main()
{
	while(cin>>a)
	{
		int len=a.size();cnt=0;pd=0;ans1=0;ans2=0;
		for(int i=0;i<len;i++)
		{
			if(a[i]=='(')
			{
				s.push('(');
			}
			else if(a[i]==')')
			{
				if(s.size()==0)
				{
					ans1++;
					pd=1;
					continue;
				}
				if(s.top()=='(')
				{
					s.pop();
				}
				else pd=1;
			}
		}
		while(s.size())
		{
			ans2++;
			pd=1;
			s.pop();
		}
		if(pd==1)
		{
			cout<<ans1+ans2<<endl;
			for(int i=1;i<=ans1;i++)
			cout<<"(";cout<<a;
			for(int i=1;i<=ans2;i++) cout<<")";
			puts("");
		}
		else puts("Match");
	}
		
}
