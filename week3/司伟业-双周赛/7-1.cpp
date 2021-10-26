#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int read()
{
	int res=0,x=1;
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

int n,ans,aa,tot;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		aa=read();
		tot=tot+aa;
		if(tot<0) tot=0;
		ans=max(ans,tot);
	}
	cout<<ans;
	return 0;
}
