#include<bits/stdc++.h>
using namespace std;
int vx[4]={-1,0,0,1};
int vy[4]={0,1,-1,0};
int m[200][200],vis[200][200],sum=0;
int n,m1;
pair<int,int> P;
void bfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int xi=x+vx[i];
		int yi=y+vy[i];
		if(xi>=1&&xi<=n&&yi>=1&&yi<=m1&&vis[xi][yi]==0&&m[xi][yi]==1)
		{
			vis[xi][yi]==1;
			bfs(xi,yi);
		}
	}
	return;
}
int main()
{
	memset(vis,0,sizeof(vis));
	cin>>n>>m1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m1;j++)
	{
		cin>>m[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m1;j++)
		{
			if(!vis[i][j]&&m[i][j]==1)
			{
				sum++;
				bfs(i,j);
			}
			else
			vis[i][j]=1;
		}
	}
	cout<<sum;
}
