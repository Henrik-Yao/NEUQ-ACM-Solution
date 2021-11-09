#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 2005
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

int n,m,a[maxn][maxn],vis[maxn][maxn],tot;
int xxx[5]={0,1,0,-1,0},yyy[5]={0,0,1,0,-1};

void dfs(int x,int y)
{
	vis[x][y]=tot;
	for(int i=1;i<=4;i++)
	{
		int xx=x+xxx[i],yy=y+yyy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&vis[xx][yy]==0&&a[xx][yy]==1)
		{
			dfs(xx,yy);
		}
	}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		a[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(vis[i][j]) continue;
		if(a[i][j]==1)
		{
			tot++;
			dfs(i,j);
		}
	}
	cout<<tot;
	return 0;
}

