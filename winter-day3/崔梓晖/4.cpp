#include <bits/stdc++.h>
using namespace std;
int fx[4]={1,-1,0,0};
int fy[4]={0,0,-1,1};
int n,m,ans=0;
int a[101][101];
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int xx=x+fx[i];
		int yy=y+fy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&a[xx][yy]!=0)
		{
			a[xx][yy]=0;
			dfs(xx,yy);
		}
	}
}
int main()
{
	cin>>n>>m;
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
			if(a[i][j]==1)
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
