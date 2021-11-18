#include <bits/stdc++.h>
using namespace std;
int fx[4]={1,0,-1,0};
int fy[4]={0,1,0,-1};
int n,m,vis[2001][2001],a[2001][2001],ans=0;
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int xx=fx[i]+x;
		int yy=fy[i]+y;
		if(xx<1||xx>n||yy<1||yy>m||vis[xx][yy]==1||a[xx][yy]==0)
		{
			continue;
		}
		vis[xx][yy]=1;
		dfs(xx,yy);
	}
}
int main()
{
	cin>>n>>m;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1&&vis[i][j]==0)
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
}
