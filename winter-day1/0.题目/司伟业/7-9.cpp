#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#define int long long
#define maxn 10005
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
	string name;
	int aa,bb;
}gg[105][maxn],g[maxn];
string a[105][10005];
int n,m,aa,bb,t[maxn],ti,nu[maxn];
string name;
map<string,int>co,num,vis;

signed main()
{
	n=read();m=read();
	memset(t,-1,sizeof(t));
	cout<<t[1];
	for(int i=1;i<=m;i++)
	{
		cin>>aa;
		for(int j=1;j<=aa;j++)
		{
			cin>>name;
			co[name]=i;
			num[name]=aa;
			a[i][j]=name;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>name>>aa>>bb;
		bb=min(bb,60);
		g[i].aa=aa;
		g[i].bb=bb;
		g[i].name=name;
		gg[co[name]][++nu[co[name]]].name=name;
		gg[co[name]][++nu[co[name]]].aa=aa;
		gg[co[name]][++nu[co[name]]].bb=bb;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[g[i].name]) continue;
		vis[g[i].name]=1;
		ti=max(g[i].aa,ti)+g[i].bb;
		int col=co[g[i].name];
		for(int j=1;j<=num[g[i].name];j++)
		{
			if(vis[gg[col][j].name]) continue;
			
		}
	}
}
