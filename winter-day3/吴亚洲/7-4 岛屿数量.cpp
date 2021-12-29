#include<bits/stdc++.h>
using namespace std;
int _map[105][105];
void dfs(int x,int y)
{
	if(!_map[x][y])
	return ;
	_map[x][y]=0;
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
}
int main()
{
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>_map[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(_map[i][j]==1)
		{
			dfs(i,j);
			num++;
		}
	}
	cout<<num;
}
