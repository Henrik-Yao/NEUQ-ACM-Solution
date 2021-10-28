#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1000005
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
queue<int>q;
int n,m,num,pd,aa,bb,s,t;
int last[maxn],de[maxn],f[maxn],d[maxn];

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
		de[bb]++;
		d[aa]++;
	}
	s=read();t=read();
	f[s]=1;
	for(int i=1;i<=n;i++)
	{
		if(de[i]==0)
		q.push(i);
	}
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=last[u];i;i=g[i].next)
		{
			int v=g[i].to;
			f[v]=f[v]+f[u];
			if(v!=t) de[v]--;
			if(de[v]==0) q.push(v);
		}
	}
	cout<<f[t]<<" ";
	for(int i=1;i<=n;i++)
	{
		if(f[i]&&d[i]==0&&i!=t)
		pd=1;
	}
	if(pd==0) puts("Yes");
	else puts("No");
	return 0;
}
