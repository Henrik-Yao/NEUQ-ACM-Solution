#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100005
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

struct edge
{
	int next,to;
}g[maxn<<1];

int n,m,k,aa,bb,num,p,ans;
int last[maxn],vis[maxn];

void dfs(int x)
{
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		if(!vis[v]) ans=2;
	}
}

void add(int from,int to)
{
	g[++num].next=last[from];
	g[num].to=to;
	last[from]=num;
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		add(aa,bb);
		add(bb,aa);
	}
	k=read();
	while(k--)
	{
		p=read();
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=p;i++)
		{
			aa=read();
			vis[aa]=1;
		}
		int pd=0;
		for(int i=1;i<=n;i++)
		{
			ans=0;
			if(!vis[i])
			dfs(i);
			if(ans>1) pd=1;
		}
		if(pd==1) puts("NO");
		else puts("YES");
	}
}

