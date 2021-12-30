#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int fx[4]={1,0,-1,0};
int fy[4]={0,1,0,-1};
int dis[1001][1001],pd[1001][1001],a[1001][1001],sx,sy,ex,ey,n,m;
struct node
{
	int x=-1;
	int y=-1;
}pre[1001][1001];
vector<node>res;
struct point
{
	int x,y,v;
	bool operator <(const point&o)const
	{
		return v>o.v;
	}
};
void bfs()
{
	memset(dis,inf,sizeof(dis));
	priority_queue<point>q;
	dis[sx][sy]=a[sx][sy];
	q.push((point){sx,sy,dis[sx][sy]});
	while(q.size()!=0)
	{
		point now=q.top();
		q.pop();
		int x=now.x;
		int y=now.y;
		if(x==ex&&y==ey)
		{
			break;
		}
		if(pd[x][y])
		continue;
		pd[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int xx=fx[i]+x;
			int yy=fy[i]+y;
			if (a[xx][yy]==-1||xx<0||xx>=n||yy<0||yy>=m) 
			continue;
			if (dis[xx][yy]>dis[x][y]+a[xx][yy])
			{
				dis[xx][yy]=a[xx][yy]+dis[x][y];
				pre[xx][yy].x=x;
				pre[xx][yy].y=y;
				q.push((point){xx,yy,dis[xx][yy]});
			}
		}
	}
}
void find(int x,int y)
{
	int qx=pre[x][y].x;
	int qy=pre[x][y].y;
	if(qx!=-1&&qy!=-1)
	{ 
	 res.push_back({qx,qy});
	 find(qx,qy);
    }
}
int main()
{
	int n,m,sx,sy,ex,ey;
	cin>>n>>m;
	cin>>sx>>sy>>ex>>ey;
	memset(a,inf,sizeof(a));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	bfs();
	find(ex,ey);
	cout<<"("<<ex<<" "<<ey<<")"<<endl;
	for (auto s:res)
	{
		cout<<"("<<s.x<<" "<<s.y<<")";
	}
	return 0;
}
