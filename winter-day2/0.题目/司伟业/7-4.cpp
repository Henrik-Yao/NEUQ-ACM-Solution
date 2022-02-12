#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define int long long
#define maxn 1005
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

struct edge{
	int next,to;
}g[maxn];
int t,num,last[maxn],vis[maxn],dep[maxn],aa,bb;

void add(int from,int to)
{
//	cout<<"sadasd"<<" "<<from<<" "<<to<<endl;
	g[++num].next=last[from];
	g[num].to=to;
	last[from]=num;
}

int rd(int deep)
{
	int l,r,val;
	val=read();
	if(val==0) return 0;
	dep[val]=deep;
	while(1)
	{
		l=rd(deep+1);
		if(l==0) break;
		add(val,l);
		add(l,val);
	}
	return val;
}

void dfs(int x)
{
	vis[x]=1;
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		if(dep[v]==dep[x]-1)
		dfs(v);
	}
}

void dfs2(int x)
{
	if(vis[x]==1)
	{
		printf("%d\n",x);
		return;
	}
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		if(dep[v]==dep[x]-1)
		dfs2(v);
	}
}

signed main()
{
	t=read();
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		memset(last,0,sizeof(last));
		num=0;
		rd(0);
		aa=read();aa=read();bb=read();
		dfs(aa);
		dfs2(bb);
	}
	return 0;
}
