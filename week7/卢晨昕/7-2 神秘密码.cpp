#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
string dfs(string a,int l,int r)
{
	int k;
	for(k=l+1;k<=r-1;k++)
	{
		if(a[k]=='[')break;
	}
	if(k==r)
	{
		int i,num=0;
		for(i=l+1;i<=r-1;i++)
		{
			if(a[i]>='0'&&a[i]<='9')num=num*10+a[i]-'0';
			else break;
		}
		string b=a.substr(i,r-i);
		string c="";
		for(i=1;i<=num;i++)
		{
			c+=b;
		}
		return c;
	}
	else
	{
		int i,num=0;
		for(i=l+1;i<=r-1;i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				num=num*10+a[i]-'0';
			}
			else break;
		}
		string b="",c="";
		for(int j=i;j<=r-1;j++)
		{
			if(a[j]=='[')
			{
				int now=j+1;
				int t=1;
				while(t)
				{
					if(a[now]=='[')t++;
					else if(a[now]==']')t--;
					if(t==0)break;
					now++;
				}
				b+=dfs(a,j,now);
				j=now;
			}
			else b+=a[j];
		}
		for(i=1;i<=num;i++)
		{
			c+=b;
		}
		return c;
	}
}
int main()
{
	string a;
	cin>>a;
	int len=a.length();
	for(int i=0;i<len;i++)
	{
		if(a[i]=='[')
		{
			int now=i+1;
			int t=1;
			while(now<len&&t)
			{
				if(a[now]=='[')t++;
				else if(a[now]==']')t--;
				if(t==0)break;
				now++;
			}
			cout<<dfs(a,i,now);
			i=now;
		}
		else cout<<a[i];
	}
	return 0;
}
