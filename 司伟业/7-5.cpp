#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 50005
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

int n,a[maxn],m,vis[maxn],pd;

void dfs(int x)
{
	if(pd==1) return;
	if(vis[x]) return;
	if(a[x]==0)
	{
		pd=1;return;
	}
	vis[x]=1;
	if(x+a[x]<n) dfs(x+a[x]);
	if(x-a[x]>=0) dfs(x-a[x]);
}

int main()
{
	n=read();
	for(int i=0;i<n;i++)
	{
		a[i]=read();
	}
	m=read();
	dfs(m);
	if(pd) printf("True");
	else printf("False");
	return 0;
}

