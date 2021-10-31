#include<bits/stdc++.h>
using namespace std;
#define mm 10005
char _map[mm][mm];
int vis[mm][mm],root[mm][mm],result[100005];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int rootnum,n,m;
int bfs(int x,int y)
{
	int ans=1;
	vis[x][y]=1;
	for(int q=0;q<4;q++)
	{
		int nx=x+dx[q],ny=y+dy[q];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&vis[nx][ny]==0&&_map[x][y]!=_map[nx][ny])
		{
			root[nx][ny]=rootnum;
			ans+=bfs(nx,ny);
		}
	}
	return ans;
}
int main()
{
	string a;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		for(int j=0;j<a.length();j++)
		_map[i][j+1]=a[j];
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(vis[x][y]==0)
		{
			rootnum++;
			root[x][y]=rootnum;
			result[rootnum]=bfs(x,y);
			cout<<result[rootnum]<<endl;
		}
		else
		cout<<result[root[x][y]]<<endl;
	}
} 
