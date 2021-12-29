#include<bits/stdc++.h>
using namespace std;
int _map[1000][1000];
bool book[1000];
int from,to,n,e;
int dis[1000];
int pre[1000];
void Dijkstra();
int main()
{
	cin>>n>>e;e/=2;
	memset(_map,0x3f,sizeof(_map));
	while(e--){
		int x,y,z;
		cin>>x>>y>>z;
		_map[x][y]=z;
		_map[y][x]=z;
	}
	for(int i=0;i<n;i++)
	_map[i][i]=0;
	cin>>from>>to;
	memset(dis,0x3f,sizeof(dis)); 
	memset(pre,-1,sizeof(pre)); 
	Dijkstra();
	int ans[1000];
	int cnt=0,t=to;
	while(t!=-1)
	{
		ans[++cnt]=t;
		t=pre[t];
	}
	cout<<from<<"-->";
	for(int i=cnt;i>=2;i--)
	cout<<ans[i]<<"-->";
	cout<<ans[1]<<":"<<dis[to];
}
void Dijkstra()
{
	int t=from;
	book[t]=1;
	for(int i=0;i<n;i++)
	dis[i]=min(dis[i],_map[t][i]);
	for(int i=0;i<n-1;i++)
	{
		int _min=0x7ffffff;
		for(int j=0;j<n;j++)
		if(!book[j]&&dis[j]<_min)
		{
			_min=dis[j];
			t=j;
		}
		book[t]=1;
		for(int j=0;j<n;j++)
		{
			if(dis[t]+_map[t][j]<dis[j])
			{
				pre[j]=t;
				dis[j]=dis[t]+_map[t][j];
			}
		}
	}
}
