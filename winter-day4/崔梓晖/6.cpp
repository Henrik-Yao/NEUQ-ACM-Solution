#include<bits/stdc++.h>
using namespace std;
long long inf=1e18;
long long n,m,q,u,v,c,d,x,y,a[1000001],dis1[1000001],dis2[1000001],pan[1000001],cost[1000001],flag;
vector<pair<long long,long long> >vec1[1000001];
vector<pair<long long,long long> >vec2[1000001];
priority_queue<pair<long long,long long> >que;
multiset<long long>st;
long long suan(long long x,long long y)
{
	return (x+y-1)/y;
}
void dij1(long long x)
{
	for(long long i=1;i<=n;i++)
	{
	 dis1[i]=inf,pan[i]=0;
	 dis1[x]=0;
    }
	que.push(make_pair(0,x));
	while(que.size())
	{
		long long u=que.top().second;
		que.pop();
		if(pan[u])continue;
		pan[u]=1;
		for(long long i=0;i<vec1[u].size();i++)
		{
			long long v=vec1[u][i].first,w=vec1[u][i].second;
			if(dis1[v]>dis1[u]+w)
			{
				dis1[v]=dis1[u]+w;
				que.push(make_pair(-dis1[v],v));
			}
		}
	}
}
void dij2(long long x)
{
	for(long long i=1;i<=n;i++)dis2[i]=inf,pan[i]=0;
	dis2[x]=0;
	que.push(make_pair(0,x));
	while(que.size())
	{
		long long u=que.top().second;
		que.pop();
		if(pan[u])continue;
		pan[u]=1;
		for(long long i=0;i<vec2[u].size();i++)
		{
			long long v=vec2[u][i].first,w=vec2[u][i].second;
			if(dis2[v]>dis2[u]+w)
			{
				dis2[v]=dis2[u]+w;
				que.push(make_pair(-dis2[v],v));
			}
		}
	}
}
int main()
{
	cin>>n>>m>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>u>>v>>c>>d;
		if(u==v)continue;
		vec1[u].push_back(make_pair(v,c));
		vec2[v].push_back(make_pair(u,d));
	}
	for(long long i=1;i<=n;i++)
    cin>>a[i];
	dij1(1);
	dij2(n);
	for(long long i=1;i<=n;i++)
	{
		if(dis1[i]==inf||dis2[i]==inf)
		continue;
		flag=dis1[i]+suan(dis2[i],a[i]);
		st.insert(flag);
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(dis1[x]==inf||dis2[x]==inf)
		{
			cout<<*(st.begin())<<endl;
			continue;
		}
		flag=dis1[x]+suan(dis2[x],a[x]);
		st.erase(st.lower_bound(flag));
		a[x]=y;
		flag=dis1[x]+suan(dis2[x],a[x]);
		st.insert(flag);
		cout<<*(st.begin())<<endl;
	}
	return 0;
}

