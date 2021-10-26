#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
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

int a[5]={0,1,0,-1,0},b[5]={0,0,1,0,-1},aa,bb;
int n,m,vis[maxn][maxn],tot,sum,ans[1000005],co[maxn][maxn];
char c[maxn][maxn];

void dfs(int x,int y)
{
	if(vis[x][y]) return;
	sum++;
	vis[x][y]=1;co[x][y]=tot;
	for(int i=1;i<=4;i++)
	{
		int xx=x+a[i];
		int yy=y+b[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&c[xx][yy]!=c[x][y])
		{
			dfs(xx,yy);
		}
	}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	cin>>(c[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vis[i][j])
			{
				tot++;sum=0;
				dfs(i,j);
				ans[tot]=sum;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		printf("%d\n",ans[co[aa][bb]]);
	}
	return 0;
}
