#include<bits/stdc++.h>
using namespace std;
int n,m,a[2001][2001],vis[2001][2001],ans=0;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
void dfs(int x,int y)
{
//	cout<<1;
//	cout<<x<<" "<<y<<endl;
	for(int i=0;i<=3;i++)
	{
		int xi,yi;
		xi=x+dx[i];
		yi=y+dy[i];
		if(xi<1||xi>n||yi<1||yi>m) continue;
		if(vis[xi][yi]==1) continue;
		if(a[xi][yi]==0) continue;
		vis[xi][yi]=1;
		dfs(xi,yi);
	}
	return ;
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
			if(!vis[i][j]&&a[i][j]==1)
			{
				ans++;
				vis[i][j]=1;
				dfs(i,j);
			}
		}
	}
	cout<<ans;
}
