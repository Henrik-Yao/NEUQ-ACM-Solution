#include<iostream>
#include<cstdio>
#include<string>
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

int n,m,ans;
int f[105][105],a1[5]={0,0,1,0,-1},a2[5]={0,1,0,-1,0};

void dfs(int x,int y)
{
	f[x][y]=0;
	for(int i=1;i<=4;i++)
	{
		int xx=x+a1[i],yy=y+a2[i];
		if(f[xx][yy]==1&&xx<=n&&xx>=1&&yy<=m&&yy>=1)
		dfs(xx,yy);
	}
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	f[i][j]=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(f[i][j]==1)
		{
			dfs(i,j);
			ans++;
		}
	}
	cout<<ans;return 0;
}
