#include<iostream>
#include<cstdio>
#include<string>
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
 
int n,q,aa,bb,cc,c[maxn];

int lowbit(int x)
{
	return x&(-x);
}

void add(int a,int x)
{
	for(int i=a;i<=n;i+=lowbit(i))
	c[i]=c[i]+x;
}

int ask(int x)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i))
	ans+=c[i];
	return ans;
}

signed main()
{
	n=read();q=read();
	for(int i=1;i<=n;i++)
	{
		aa=read();
		add(i,aa);
	}
	
	for(int i=1;i<=q;i++)
	{
		aa=read();bb=read();cc=read();
		if(aa==1)
		{
			add(bb,cc);
		}
		else 
		printf("%lld\n",ask(cc)-ask(bb-1));
	}
	return 0;
}
