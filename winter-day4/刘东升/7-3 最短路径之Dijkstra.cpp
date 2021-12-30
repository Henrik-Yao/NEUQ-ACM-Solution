#include<bits/stdc++.h>
using namespace std;
int _map[1000][1000];
int dis[1000];//到起点的最短距离 
int pre[1000];//记录前驱节点 
bool book[1000];//被当作起点搜索过 
int from,to,n,e;
void Dijkstra()
{
	int t=from;
	book[t]=1;//标记起点已搜索 
	for(int i=0;i<n;i++)
	dis[i]=min(dis[i],_map[t][i]);//初始化和起点相连的点的dis 
	for(int i=0;i<n-1;i++)
	{
		int _min=0x7ffffff;
		for(int j=0;j<n;j++)
		if(!book[j]&&dis[j]<_min)//找下一个搜索的起点 
		{
			_min=dis[j];
			t=j;
		}
		book[t]=1;
		for(int j=0;j<n;j++)
		{
			if(dis[t]+_map[t][j]<dis[j])
			{
				pre[j]=t;//符合条件，记录前驱 
				dis[j]=dis[t]+_map[t][j];
			}
		}
	}
}
int main()
{
	cin>>n>>e;
	e/=2;//细节拿捏住 
	memset(_map,0x3f,sizeof(_map));//初始化_map 
	while(e--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		_map[x][y]=z;
		_map[y][x]=z;
	}
	for(int i=0;i<n;i++)
	_map[i][i]=0;//自己到自己距离为0 
	cin>>from>>to;
	memset(dis,0x3f,sizeof(dis));//初始化dis 
	memset(pre,-1,sizeof(pre));//初始化pre 
	Dijkstra();
	int ans[1000];//纪录答案路径 
	int cnt=0,t=to;
	while(t!=-1)//t=pre[起点]时结束 
	{
		ans[++cnt]=t;
		t=pre[t];
	}
	cout<<from<<"-->";
	for(int i=cnt;i>=2;i--)
	cout<<ans[i]<<"-->";
	cout<<ans[1]<<":"<<dis[to];
}
