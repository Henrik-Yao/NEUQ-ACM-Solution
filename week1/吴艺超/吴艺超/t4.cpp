#include<bits/stdc++.h>
#include<cmath>
#define R register
#define N 999
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48),ch=getchar();
	}
	return x*f;

}
int n,tot=1;
void dfs(int x)
{
	if(x==1)
	{
		tot++;
		return;
	}
	for(int i=1;i<x;i++)
	{
		if(x%i==0)dfs(i);
	}
	tot++;
}
int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			dfs(i);
		}
	}
	cout<<tot;
	return 0;
}
