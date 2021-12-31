#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int n,m;
struct node
{
	int pre,to,nex;
	int val;
}e[205];
int head[205];
int cnt;
void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].pre=a;
	e[cnt].val=1;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
int dis[205][205];//iµ½j
int v[205];
int opera[205];
void dijkstra(int a)
{
	priority_queue<pair<int,int> >q;
	memset(v,0,sizeof(v));
	memset(dis[a],0x3f,sizeof(dis[a]));
	dis[a][a]=0;
	q.push({0,a});
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=e[i].nex)
		{
			int y=e[i].to;
			int val=e[i].val;
			if(dis[a][y]>dis[a][x]+val)
			{
				dis[a][y]=dis[a][x]+val;
				q.push({-dis[a][y],y});
			}
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		memset(opera,0,sizeof(opera));
		memset(head,0,sizeof(head));
		for(int i=1;i<=n;i++)
		{
			int a,k;
			cin>>a>>k;
			for(int j=1;j<=k;j++)
			{
				int b;
				cin>>b;
				add(a,b);
			}
		}
		
		for(int i=1;i<=m;i++)
		{
			int a,b;
			cin>>a>>b;
			if(opera[a])
			{
				if(dis[a][b]!=inf)
				{
					cout<<dis[a][b]<<endl;
				}
				else cout<<"connection impossible"<<endl;
			}
			else
			{
				dijkstra(a);
				opera[a]=1;
				if(dis[a][b]!=inf)
				{
					cout<<dis[a][b]<<endl;
				}
				else cout<<"connection impossible"<<endl;
			}
		}
	}
	return 0;
}

