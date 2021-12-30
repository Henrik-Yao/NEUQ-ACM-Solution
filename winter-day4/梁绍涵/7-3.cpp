#include<bits/stdc++.h>
using namespace std;
int n,m;
const int INF=0x3f3f3f;
int vis[21000];
int edge[21000][21000],dis[21000],path[21000],ui;
typedef pair<int,int> P;
priority_queue<P,vector<P> ,greater<P> >q;
void dij(int x)
{
	P a,b;
	a.first=0;
	a.second=x;
	q.push(a);
	while(!q.empty())
	{
		b=q.top();
		q.pop();
		int u=b.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<n;i++)
		{
			if(edge[u][i]==INF) continue;
			if(dis[u]+edge[u][i]<dis[i])
			{
				dis[i]=dis[u]+edge[u][i];
				path[i]=u;
				if(vis[i]) continue;
				b.first=dis[i];
				b.second=i;
				q.push(b);
			}
		}
	}
	return;
}
void find(int x)
{
	if (path[x]==ui) 
	{
		cout<<ui;
	}
	else 
	{
		find(path[x]);
	}
	cout <<"-->"<<x;
	return;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	edge[i][j]=INF;
	for(int i=0;i<m/2;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge[x][y]=z;
		edge[y][x]=z;
	}
	for(int i=0;i<n;i++)
	dis[i]=INF;
	int vi;
	cin>>ui>>vi;
	dis[ui]=0;
	memset(path,-1,sizeof(path));
	dij(ui);
//	cout<<"x";
//	path[ui]=ui;
	find(vi);
	cout<<":"<<dis[vi];
//	cout<<
}
