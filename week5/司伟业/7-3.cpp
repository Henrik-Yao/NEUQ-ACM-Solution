#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 20005
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
int n,m,aa,bb,num,last[maxn],vis[maxn];

void add(int from,int to)
{
	g[++num].next=last[from];
	g[num].to=to;
	last[from]=num;
}

void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	int a[maxn],tot=0;
	if(x==1) printf("0 ");
	else printf("%d ",x-1);
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		if(!vis[v])
		a[++tot]=v;
	}
	sort(a+1,a+1+tot);
	for(int i=1;i<=tot;i++)
	{
		dfs(a[i]);
	}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		aa++;bb++;
		add(aa,bb);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		dfs(i);
	}
	return 0;
}
