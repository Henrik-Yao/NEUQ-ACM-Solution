#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f;
int edge[200][200];
int n,m;
int dis[200],vis[200];
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> >q;
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
		int u=b.second,v;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<n;i++)
		{
	//		if(edge[u][i]==INF) continue;
			if(dis[u]+edge[u][i]<dis[i])
			{
				dis[i]=dis[u]+edge[u][i];
				if(vis[i]) continue;
				b.first=dis[i];
				b.second=i;
				q.push(b);
			}
		}
		return;
	}
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		edge[i][j]=INF;
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			edge[x][y]=z;
			edge[y][x]=z;
//			cout<<endl;
		}
		int max1=100000,pos;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			dis[j]=INF;
			dis[i]=0;
			dij(i);	
			int sum=0;
			for(int j=0;j<n;j++)
			sum+=dis[j];
//			cout<<i<<" "<<sum<<endl;
			if(sum<max1)
			{
				max1=sum;

				pos=i;
			}
			
		}
		cout<<pos<<endl;
	}
}
