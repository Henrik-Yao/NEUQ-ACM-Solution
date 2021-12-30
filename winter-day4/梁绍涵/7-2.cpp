#include<bits/stdc++.h>
using namespace std;
int n,m;
const int INF=0x3f3f3f;
int vis[210];
int edge[210][210],dis[210];
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
				if(vis[i]) continue;
				b.first=dis[i];
				b.second=i;
				q.push(b);
			}
		}
	}
	while(!q.empty())
	q.pop();
	return;
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		edge[i][j]=INF;
		for(int i=0;i<n;i++)
		{
			int x,t;
			cin>>x>>t;
			while(t--)
			{
				int y;
				cin>>y;
				edge[x][y]=1;
			}
		}
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			for(int j=0;j<n;j++)
			{
				dis[j]=INF;
			}
			memset(vis,0,sizeof(vis));
			dis[x]=0;
			dij(x);
			if(dis[y]==INF) cout<<"connection impossible"<<endl;
			else cout<<dis[y]<<endl;
		}
	}
} 
