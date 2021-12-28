#include<bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int m,n,s=0,fx,fy;
bool a[2005][2005];//棋盘
bool v[2005][2005];//标记
void dfs(int x,int y)
{
	v[x][y]=1;
	for(int i=0;i<4;i++)//移动
	{
		fx=dx[i]+x;
		fy=dy[i]+y;
		if(fx<1||fx>m||fy<1||fy>n) continue;//超界
		if(v[fx][fy]==1||a[fx][fy]==0) continue;
		dfs(fx,fy);
	}
}
int main()
{
	memset(a,0,sizeof(a));
	memset(v,0,sizeof(v));
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0||v[i][j]==1) continue;
			dfs(i,j);
			s++;
		}
	}
	cout<<s;
	return 0;
}