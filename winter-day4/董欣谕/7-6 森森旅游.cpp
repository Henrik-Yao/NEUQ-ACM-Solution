#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
const ll mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct edge{
	ll to,next,tour,money;
}ed1[200001],ed2[200001];
ll head1[100001],cnt1=0,head2[100001],cnt2=0;
ll a[100001],tcost[100001],mcost[100001],mincost[100001];
bool vis[100001];
multiset<ll>s;
ll n,m,q;
void add1(ll u,ll v,ll money,ll tour){
	ed1[++cnt1].to=v;
	ed1[cnt1].tour=tour;
	ed1[cnt1].money=money;
	ed1[cnt1].next=head1[u];
	head1[u]=cnt1;
}
void add2(ll u,ll v,ll money,ll tour){
	ed2[++cnt2].to=v;
	ed2[cnt2].tour=tour;
	ed2[cnt2].money=money;
	ed2[cnt2].next=head2[u];
	head2[u]=cnt2;
}
void dij2(){
	memset(tcost,INF,sizeof tcost);
	memset(vis,0,sizeof vis);
	tcost[n]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,n});
	while (!q.empty()){
		ll u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (ll i=head2[u];i;i=ed2[i].next){
			ll v=ed2[i].to;
			if (tcost[v]>tcost[u]+ed2[i].tour){
				tcost[v]=tcost[u]+ed2[i].tour;
				q.push({tcost[v],v});
			}
		}
	}
}
void dij1(){
	memset(mcost,INF,sizeof mcost);
	memset(vis,0,sizeof vis);
	mcost[1]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,1});
	while (!q.empty()){
		ll u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (ll i=head1[u];i;i=ed1[i].next){
			ll v=ed1[i].to;
			if (mcost[v]>mcost[u]+ed1[i].money){
				mcost[v]=mcost[u]+ed1[i].money;
				q.push({mcost[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	for (ll i=1;i<=m;i++){
		ll u,v,w1,w2;
		cin>>u>>v>>w1>>w2;
		if (u!=v) add1(u,v,w1,w2),add2(v,u,w1,w2);
	}
	for (ll i=1;i<=n;i++)
		cin>>a[i];
	dij1();
	dij2();
	for (ll i=1;i<=n;i++){
		if (tcost[i]!=INF&&mcost[i]!=INF){
			mincost[i]=mcost[i]+(tcost[i]+a[i]-1)/a[i];
			s.insert(mincost[i]);
		}
	}
	while (q--){
		ll x,w;
		cin>>x>>w;
		a[x]=w;
		if (tcost[x]!=INF&&mcost[x]!=INF){
			s.erase(s.find(mincost[x]));
			mincost[x]=mcost[x]+(tcost[x]+a[x]-1)/a[x];
			s.insert(mincost[x]);
		}
		auto it=s.begin();
		cout<<*it<<endl;
	}
	return 0;
} 
