#include<bits/stdc++.h>
#define pil pair<int, long long>
using namespace std;
typedef long long ll;
int n,m,q,u,v,c,d;
struct tu
{
	int num;
	ll dis;
	friend bool operator < (const tu &a,const tu &b) { 
	return a.dis>b.dis;
	}
};
vector <pil> cash1[100005],voucher1[100005];
ll cash2[100005],voucher2[100005],sum[100005],hui[100005];
bool jud1[100005],jud2[100005];
multiset <ll> mincost;
priority_queue<tu> Q;
void dijskra(int N,vector<pil> V[],ll Dis[],bool jud[])
{
	fill (Dis + 1, Dis + n + 1, 1e18);
	Dis[N] = 0;
	Q.push(tu{N,0});
	while(!Q.empty())
	{
		long long w;
		int now = Q.top().num;
		Q.pop();
		if(jud[now]) continue;
		jud[now] = 1;
		for(int i=0;i<(int)V[now].size();i++)
		{
			v=V[now][i].first;
			w=V[now][i].second;
			if(Dis[v]>Dis[now]+w)
			{
				Dis[v] = Dis[now] + w;
				Q.push(tu{v,Dis[v]});
			}
		}
	}
}
int main()
{
	cin>>n>>m>>q;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>c>>d;
		cash1[u].push_back({v,c});
		voucher1[v].push_back({u,d});
	}
	for(int i=1;i<=n;i++) cin>>hui[i];
	dijskra(1,cash1,cash2,jud1);
	dijskra(n,voucher1,voucher2,jud2);
	for(int i=1;i<=n;i++)
	{
		if(cash2[i]>=1e18||voucher2[i]>=1e18) continue;
		mincost.insert(sum[i] = cash2[i]+(voucher2[i]+hui[i]-1)/hui[i]);
	}
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		if(!sum[a]||hui[a] == b)
		{
			cout<<*mincost.begin();
		}
		else 
		{
			mincost.erase(mincost.find(sum[a]));
			hui[a] = b;
			mincost.insert(sum[a] = cash2[a]+(voucher2[a]+hui[a]-1)/hui[a]);
			cout<<*mincost.begin();
		}
		cout<<'\n';
	}
	return 0;
}
