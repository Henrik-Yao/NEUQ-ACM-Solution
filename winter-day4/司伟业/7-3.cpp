#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
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
	int c,val;
};
struct edge{
	int next,to,dis;
}g[maxn<<1];
int n,m,aa,bb,cc,num,last[maxn],vis[maxn],d[maxn],pre[maxn];
int cnt,path[maxn],s,t;
priority_queue<node>q;
bool operator<(node a,node b)
{
	return a.val>b.val;
}

void add(int from,int to,int dis)
{
	g[++num].next=last[from];
	g[num].to=to;
	g[num].dis=dis;
	last[from]=num;
}

void dj()
{
	for(int i=0;i<=n;i++) d[i]=2e9;
	q.push((node){s,0});d[s]=0;
	while(q.size())
	{
		node u=q.top();q.pop();
		if(vis[u.c]) continue;
		vis[u.c]=1;
		for(int i=last[u.c];i;i=g[i].next)
		{
			int v=g[i].to;
			if(d[v]>d[u.c]+g[i].dis)
			{
				d[v]=d[u.c]+g[i].dis;
				q.push((node){v,d[v]});
				pre[v]=u.c;
			}
		}
	}
	int x=t;
	while(1)
	{
		path[++cnt]=x;
		if(x==s) break;
		x=pre[x];
	}
}

signed main()
{
	n=read();m=read();m=m/2;
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();cc=read();
		add(aa,bb,cc);
		add(bb,aa,cc);
	}
	s=read();t=read();
	dj();
	if(s==t){
		printf("%d-->%d:%d",s,t,d[t]);
		return 0;
	}
	for(int i=cnt;i>=1;i--)
	{
		if(i!=1) printf("%d-->",path[i]);
		else printf("%d:%d",path[i],d[t]);
	}
	return 0;
}
