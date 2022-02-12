#include<bits/stdc++.h>

using namespace std;
int n,m;
int ma[105][105];
int ans;
int dx[5]={0,1,0,0,-1};
int dy[5]={0,0,1,-1,0};
void dfs(int x,int y)
{
	ma[x][y]=0;
	for(int i=1;i<=4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			if(ma[xx][yy]==1)dfs(xx,yy);
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
			cin>>ma[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ma[i][j]==1)
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
