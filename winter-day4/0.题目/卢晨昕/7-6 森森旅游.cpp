#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
ll n,m,q;
ll a[100005];

struct node
{
	ll pre,to,nex;
	ll c,d;
}e1[200005],e2[200005];
ll head1[200005];
ll head2[200005];
ll cnt1,cnt2;
void add1(ll a,ll b,ll c,ll d)
{
	e1[++cnt1].to=b;
	e1[cnt1].pre=a;
	e1[cnt1].c=c;
	e1[cnt1].d=d;
	e1[cnt1].nex=head1[a];
	head1[a]=cnt1;
}
void add2(ll a,ll b,ll c,ll d)
{
	e2[++cnt2].to=b;
	e2[cnt2].pre=a;
	e2[cnt2].c=c;
	e2[cnt2].d=d;
	e2[cnt2].nex=head2[a];
	head2[a]=cnt2;
}

ll dis1[100005];
ll dis2[100005];
ll v1[100005];
ll v2[100005];
void dijkstra1()
{
	priority_queue<pair<ll,ll> >q;
	memset(v1,0,sizeof(v1));
	memset(dis1,0x3f,sizeof(dis1));
	dis1[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		ll x=q.top().second;
		q.pop();
		if(v1[x])continue;
		v1[x]=1;
		for(ll i=head1[x];i;i=e1[i].nex)
		{
			ll y=e1[i].to;
			ll c=e1[i].c;
			if(c+dis1[x]<dis1[y])
			{
				dis1[y]=c+dis1[x];
				q.push({-dis1[y],y});
			}
		}
	}
}
void dijkstra2()
{
	priority_queue<pair<ll,ll> >q;
	memset(v2,0,sizeof(v2));
	memset(dis2,0x3f,sizeof(dis2));
	dis2[n]=0;
	q.push({0,n});
	while(!q.empty())
	{
		ll x=q.top().second;
		q.pop();
		if(v2[x])continue;
		v2[x]=1;
		for(ll i=head2[x];i;i=e2[i].nex)
		{
			ll y=e2[i].to;
			ll d=e2[i].d;
			if(d+dis2[x]<dis2[y])
			{
				dis2[y]=d+dis2[x];
				q.push({-dis2[y],y});
			}
		}
	}
}
multiset<ll>minCost;//set 
ll tran[100005];
int main()
{
	cin>>n>>m>>q;
	for(ll i=1;i<=m;i++)
	{
		ll a,b;
		ll c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a==b)continue;
		add1(a,b,c,d);
		add2(b,a,c,d);//建一个反向的图 
	}
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dijkstra1();
	dijkstra2();
	for(ll i=1;i<=n;i++)
	{
		if(dis1[i]==inf||dis2[i]==inf)continue;
		minCost.insert(tran[i]=dis1[i]+(dis2[i]+a[i]-1)/a[i]);
	}
	for(ll i=1;i<=q;i++)
	{
		ll x;
		ll y;
		scanf("%lld%lld",&x,&y);
		if(!a[x]||a[x]==y)
		{
			printf("%lld\n",*minCost.begin());
		}
		else
		{
			minCost.erase(minCost.find(tran[x]));
			a[x]=y;
			minCost.insert(tran[x]=dis1[x]+(dis2[x]+a[x]-1)/a[x]);
			printf("%lld\n",*minCost.begin());
		}
	}
	return 0;
}
