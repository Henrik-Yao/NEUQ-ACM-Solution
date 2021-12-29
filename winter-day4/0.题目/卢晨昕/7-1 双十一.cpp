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
void add(int a,int b,int c)
{
	e[++cnt].to=b;
	e[cnt].pre=a;
	e[cnt].val=c;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
int dis[105];
int v[105];
int ans=inf;
int anss;
void dijkstra(int x)
{
	priority_queue<pair<int,int> >q;
	dis[x]=0;
	q.push({0,x});
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
				q.push({-dis[y],y});
			}
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		cnt=0;
		ans=inf;
		anss=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<=m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			add(a,b,c);
			add(b,a,c);
		}
		for(int i=0;i<n;i++)
		{
			int sum=0;
			memset(dis,0x3f,sizeof(dis));
			memset(v,0,sizeof(v));
			dijkstra(i);
			for(int j=0;j<n;j++)
			{
				sum+=dis[j];
			}
			if(sum<ans)
			{
				ans=sum;
				anss=i;
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}

