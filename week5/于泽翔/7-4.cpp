#include <bits/stdc++.h>
using namespace std;
int a[2020][2020],dx[4]={0, -1, 0, 1}, dy[4]={-1, 0, 1, 0}, m, n, ans=0;

void dfs(int x, int y)
{
	a[x][y]=0;
	
	for(int i=0; i<4; i++)
	{
		int xx=x+dx[i], yy=y+dy[i];
		if(xx<0||yy<0||xx==m||yy==n)
			continue;
		if(a[xx][yy]==0)
			continue;
		dfs(xx, yy);
	}
}
int main(void)
{
	cin>>m>>n;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
		{
			if(a[i][j]==0)
				continue;
			dfs(i, j);
			ans++;
		}
	cout<<ans;
	
	return 0;
}