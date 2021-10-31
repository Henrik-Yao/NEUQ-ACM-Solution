#include <bits/stdc++.h>
using namespace std;
int fx[4]={1,0,-1,0};
int fy[4]={0,1,0,-1};
int n,m,f[1001][1001],ans[1000001];
char a[1001][1001];
void dfs(int x,int y,int now,int pos)
{
	if(x<1||x>n||y<1||y>n||f[x][y]!=-1||a[x][y]-'0'!=now)
	return;
		f[x][y]=pos;
		ans[pos]++;
		for(int i=0;i<4;i++)
		{
			int xx=fx[i]+x;
			int yy=fy[i]+y;
			dfs(xx,yy,!now,pos);
		}
}
int main()
{
	memset(f,-1,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(f[x][y]==-1)
		dfs(x,y,a[x][y]-'0',i);
		else
		ans[i]=ans[f[x][y]];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
