#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 200005
using namspace std;

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
int n,num,last[maxn],s[maxn],vis[maxn];
char a[10],f1[10],f2[10],sex;
int aa,bb,cc,q,pd;

void add(int from,int to)
{
	g[++num].next=last[from];
	g[num].to=to;
	last[from]=num;
}

void dfs(int x,int t)
{
	if(t==6) return;
	vis[x]=1;
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		dfs(v,t+1);
	}
}

void dfs1(int x,int t)
{
	if(pd) return;
	if(t==6) return;
	if(vis[x])
	{
		pd=1;
		return;
	}
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		dfs1(v,t+1);
	}
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>a>>sex>>f1>>f2;
		if(a[0]!='-') aa=(a[0]-'0')*10000+(a[1]-'0')*1000+(a[2]-'0')*100+(a[3]-'0')*10+(a[4]-'0');
		if(f1[0]!='-') bb=(f1[0]-'0')*10000+(f1[1]-'0')*1000+(f1[2]-'0')*100+(f1[3]-'0')*10+(f1[4]-'0');
		if(f2[0]!='-') cc=(f2[0]-'0')*10000+(f2[1]-'0')*1000+(f2[2]-'0')*100+(f2[3]-'0')*10+(f2[4]-'0');
		if(f1[0]!='-') add(aa,bb),s[bb]=0;
		if(f2[0]!='-') add(aa,cc),s[cc]=1;
		if(sex=='M') s[aa]=0;//0~~~?
		else s[aa]=1;//1~~~? 
//		cout<<aa<<" "<<bb<<" "<<cc<<endl; 
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		cin>>f1>>f2;pd=0;
		bb=(f1[0]-'0')*10000+(f1[1]-'0')*1000+(f1[2]-'0')*100+(f1[3]-'0')*10+(f1[4]-'0');
		cc=(f2[0]-'0')*10000+(f2[1]-'0')*1000+(f2[2]-'0')*100+(f2[3]-'0')*10+(f2[4]-'0');
		if(s[bb]==s[cc])
		{
			puts("Never Mind");
			continue;
		}
		memset(vis,0,sizeof(vis));
		dfs(bb,1);
		dfs1(cc,1);
		if(pd) 
		{
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
} 
