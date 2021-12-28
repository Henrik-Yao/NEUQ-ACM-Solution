#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
bool vis[10005];
int pre[100000],num=1,dist[10005];
int from,to,m,n;
void dijkstra(int t)
{
	vis[t]=1;
	memset(dist,0x3f,sizeof(dist));
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<n;i++)
		dist[i]=min(dist[i],a[t][i]);
	for(int i=0;i<n-1;i++)
	{
		int x=0x7ffffff;
		for(int j=0;j<n;j++)
		if(!vis[j]&&dist[j]<x)
		{
			x=dist[j];
			t=j;
		}
		vis[t]=1;
		for(int j=0;j<n;j++)
		{
			if(dist[t]+a[t][j]<dist[j])
			{
				pre[j]=t;
				dist[j]=dist[t]+a[t][j];
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m/2;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=0;i<n;i++)
		a[i][i]=0;
	cin>>from>>to;
	dijkstra(from);
	int path[1000];
	int cnt=0,t=to;
	while(t!=-1)
	{
		path[++cnt]=t;
		t=pre[t];
	}
	cout<<from<<"-->";
	for(int i=cnt;i>=2;i--)
	cout<<path[i]<<"-->";
	cout<<path[1]<<":"<<dist[to];
	return 0;
}
