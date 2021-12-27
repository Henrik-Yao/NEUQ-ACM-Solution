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

struct node{
	int last,next,val;
}g[maxn];
int n,m,k,aa;

signed main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)
	{
		g[i].last=i-1;
		g[i].next=i+1;
		g[i].val=i;
	}
	g[1].last=n;g[n].next=1;
	int l=1;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int x=1;x<m;x++) l=g[l].last;
			printf("%d ",g[l].val);
			g[g[l].last].next=g[l].next;
			g[g[l].next].last=g[l].last;
		}
		else
		{
			for(int x=1;x<k;x++) l=g[l].next;
			printf("%d ",g[l].val);
			g[g[l].last].next=g[l].next;
			g[g[l].next].last=g[l].last;
		}
	}
	return 0;
}
