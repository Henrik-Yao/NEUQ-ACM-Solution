#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int m,n;
int ma[2005][2005];
int dx[5]={0,1,0,0,-1};
int dy[5]={0,0,1,-1,0};
int ans=0;
void dfs(int x,int y)
{
	for(int i=1;i<=4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=1&&yy>=1&&xx<=m&&yy<=n)
		{
			if(ma[xx][yy]==1)
			{
				ma[xx][yy]=0;
				dfs(xx,yy);
			}
		}
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>ma[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ma[i][j]==1)
			{
				ans++;
			    ma[i][j]=0;
			    dfs(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
}
