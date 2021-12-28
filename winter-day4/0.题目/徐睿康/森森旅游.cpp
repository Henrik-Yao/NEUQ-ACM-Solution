#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
ll INF=1e18;
ll n,m,q,u,v,c,d,x,y,a[N],dis1[N],dis2[N],pan[N],cost[N],flag;
vector<pair<ll,ll> >vec1[N];
vector<pair<ll,ll> >vec2[N];
priority_queue<pair<ll,ll> >que;
multiset<ll>st;
ll suan(ll x,ll y){
	if(x==0)return 0;
	else if(x<=y)return 1;
	else if(x%y==0)return x/y;
	else return (x/y)+1;
}
void dij1(ll x){
	for(ll i=1;i<=n;i++)dis1[i]=INF,pan[i]=0;
	dis1[x]=0;
	que.push(make_pair(0,x));
	while(que.size()){
		ll u=que.top().second;
		que.pop();
		if(pan[u])continue;
		pan[u]=1;
		for(ll i=0;i<vec1[u].size();i++){
			ll v=vec1[u][i].first,w=vec1[u][i].second;
			if(dis1[v]>dis1[u]+w){
				dis1[v]=dis1[u]+w;
				que.push(make_pair(-dis1[v],v));
			}
		}
	}
}
void dij2(ll x){
	for(ll i=1;i<=n;i++)dis2[i]=INF,pan[i]=0;
	dis2[x]=0;
	que.push(make_pair(0,x));
	while(que.size()){
		ll u=que.top().second;
		que.pop();
		if(pan[u])continue;
		pan[u]=1;
		for(ll i=0;i<vec2[u].size();i++){
			ll v=vec2[u][i].first,w=vec2[u][i].second;
			if(dis2[v]>dis2[u]+w){
				dis2[v]=dis2[u]+w;
				que.push(make_pair(-dis2[v],v));
			}
		}
	}
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld%lld",&u,&v,&c,&d);
		if(u==v)continue;
		vec1[u].push_back(make_pair(v,c));
		vec2[v].push_back(make_pair(u,d));
	}
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	dij1(1);
	dij2(n);
	for(int i=1;i<=n;i++){
		if(dis1[i]==INF||dis2[i]==INF)
		continue;
		flag=dis1[i]+suan(dis2[i],a[i]);
		st.insert(flag);
	}
	for(ll i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		if(dis1[x]==INF||dis2[x]==INF){
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
