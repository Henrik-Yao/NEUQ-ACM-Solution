#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1005
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

int n,m,k,aa,bb,num,s,t;
int last[maxn],vis[maxn];

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
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		dfs(v);
	}
}

int main()
{
	n=read();k=read();m=read();
	for(int i=1;i<=n;i++)
	vis[i]=1;
	for(int i=1;i<=k;i++)
	{
		aa=read();vis[aa+1]=0;
	}
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		aa++;bb++;
		add(aa,bb);
		add(bb,aa);
	}
	s=read();t=read();
	s++;t++;
	vis[s]=0;
	if(vis[t])
	{
		printf("The city %d is not safe!\n",t-1);
		return 0;
	}
	dfs(s);
	if(vis[t]) printf("The city %d can arrive safely!\n",t-1);
	else printf("The city %d can not arrive safely!\n",t-1);
	return 0;
}
