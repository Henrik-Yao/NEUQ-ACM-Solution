#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ax{
	int net,to;
	int dis;
}a1[200005],a2[200005];
int head1[200005],tot1,m,n,head2[200005],tot2,q;
int xjin[200005],lvjin[200005];
bool vis[200005];
int a[200005];
int jin[200005];
multiset<int> mincost;
void add1(int net,int to,int dis)
{
	a1[++tot1].to=to;
	a1[tot1].dis=dis;
	a1[tot1].net=head1[net];
	head1[net]=tot1;
}
void add2(int net,int to,int dis)
{
	a2[++tot2].to=to;
	a2[tot2].dis=dis;
	a2[tot2].net=head2[net];
	head2[net]=tot2;
}
void dijkstra1(int s,int *dist)//正向现金跑 
{
	 priority_queue< pair<int,int> >q;
	 for(int i=1;i<=n;i++)
	 	dist[i]=LLONG_MAX;
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head1[x];i;i=a1[i].net)
		{
			int to=a1[i].to;
			int dis=a1[i].dis;
			if(dist[to]>dist[x]+dis){
				dist[to]=dist[x]+dis;
				q.push(make_pair(-dist[to],to));
			}
		}
	}
}
void dijkstra2(int s,int *dist)//反向代金券跑 
{
	 priority_queue< pair<int,int> >q;
	 for(int i=1;i<=n;i++)
	 	dist[i]=LLONG_MAX;
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head2[x];i;i=a2[i].net)
		{
			int to=a2[i].to;
			int dis=a2[i].dis;
			if(dist[to]>dist[x]+dis){
				dist[to]=dist[x]+dis;
				q.push(make_pair(-dist[to],to));
			}
		}
	}
}
signed main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int x,y,z,d;
		cin>>x>>y>>z>>d;
		if(x==y)continue;
		add1(x,y,z);
		add2(y,x,d);
	}
	dijkstra1(1,xjin);dijkstra2(n,lvjin);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(xjin[i]>LLONG_MAX-10 || lvjin[i]>LLONG_MAX-10)continue;
		mincost.insert(jin[i]=xjin[i]+(lvjin[i]+a[i]-1)/a[i]);
	}
	for(int i=1;i<=q;i++)
	{
		int num,b;
		cin>>num>>b;
		if(!jin[num] || a[num]==b){
			cout<<*mincost.begin()<<endl;
		}
		else
		{
		 	 mincost.erase(mincost.find(jin[num]));
			a[num]=b;
			mincost.insert(jin[num]=xjin[num]+(lvjin[num]+a[num]-1)/a[num]);
			cout<<*mincost.begin()<<endl;
		}
	}
	return 0;
}

