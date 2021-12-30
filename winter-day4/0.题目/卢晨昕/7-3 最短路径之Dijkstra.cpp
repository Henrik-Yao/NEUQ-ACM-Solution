#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n,m;
struct node
{
	int pre,to,nex;
	ll val;
}e[20005];
int head[20005];
int cnt;
void add(int a,int b,int c)
{
	e[++cnt].to=b;
	e[cnt].pre=a;
	e[cnt].val=c;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
ll dis[20005];
int v[20005];
int be,en;
int pre[20005];
void dijkstra(int a)
{
	priority_queue<pair<ll,int> >q;
	memset(v,0,sizeof(v));
	memset(dis,0x3f,sizeof(dis));
	dis[a]=0;
	pre[a]=a;
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
			if(dis[y]>dis[x]+val)
			{
				dis[y]=dis[x]+val;
				pre[y]=x;//记录前驱节点 
				q.push({-dis[y],y});
			}
		}
	}
}
void dfs(int x)
{
	if(x==be)
	{
		cout<<x<<"-->";
	}
	else
	{
		dfs(pre[x]);
		if(x!=en)cout<<x<<"-->";
		else cout<<x<<":";
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m/2;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	cin>>be>>en;
	dijkstra(be);
	if(be!=en)dfs(en);
	else cout<<be<<"-->"<<be<<":";
	cout<<dis[en];
	return 0;
}
