#include<bits/stdc++.h>
using namespace std;
int m,n,sh[200][200],ans;
int mx[5]={0,1,0,0,-1};
int my[5]={0,0,1,-1,0};
void dfs(int x,int y)
{
	sh[x][y]=0;
	for(int i=1;i<=4;i++)
	{
		int xx=x+mx[i];
		int yy=y+my[i];
		if(xx<1||xx>m||yy<1||yy>n){continue;}
		if(sh[xx][yy]==0){continue;}
		dfs(xx,yy);
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>sh[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(sh[i][j]==0){continue;}
			dfs(i,j);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
