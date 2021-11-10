#include<bits/stdc++.h>
using namespace std;
int _map[2005][2005],pass[2005][2005];
int m,n,cnt;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y)
{
	pass[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(!pass[xx][yy]&&xx>=1&&xx<=m&&yy>=1&&yy<=n&&_map[xx][yy]==1)
		dfs(xx,yy);
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	cin>>_map[i][j];
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(!pass[i][j]&&_map[i][j]==1)
		{
			pass[i][j]=1;
			cnt++;
			dfs(i,j);
		}
	}
	cout<<cnt;
}
