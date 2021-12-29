#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll _=5e5+7;
const ll oo=0x3f3f3f3f3f3f3fll;
ll read() {
    ll x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}          
ll n,m,q,a[_],vis[_],dis[2][_];
vector<pair<ll,ll> > G[2][_];
void spfa(ll opt,ll S) {
    queue<ll> q;
    for(ll i=1;i<=n;++i) dis[opt][i]=0x3f3f3f3f3f3f3fll,vis[i]=0;
    dis[opt][S]=0;
    q.push(S);
    while(!q.empty()) {
        ll u=q.front();q.pop();
        vis[u]=0;
        for(auto x:G[opt][u]) {
            ll v=x.first;
            if(dis[opt][v]>dis[opt][u]+x.second) {
                dis[opt][v]=dis[opt][u]+x.second;                
                if(!vis[v]) vis[v]=1,q.push(v);
            }
        }
    }
}
int main() {
    // freopen("a.in","r",stdin);
    n=read(),m=read(),q=read();
    for(ll i=1;i<=m;++i) {
        ll u=read(),v=read(),c=read(),d=read();
        G[0][u].push_back(make_pair(v,c));
        G[1][v].push_back(make_pair(u,d));
    }
    for(ll i=1;i<=n;++i) a[i]=read();
    spfa(0,1),spfa(1,n);
    multiset<ll> dsr;
    for(ll i=1;i<=n;++i)
        if(dis[0][i]!=oo&&dis[1][i]!=oo)
            dsr.insert(dis[0][i]+(dis[1][i]+a[i]-1)/a[i]);
    while(q-->0) {
        ll x=read(),y=read();
        if(dis[0][x]!=oo&&dis[1][x]!=oo) {
            dsr.erase(dsr.find(dis[0][x]+(dis[1][x]+a[x]-1)/a[x]));
            a[x]=y;
            dsr.insert(dis[0][x]+(dis[1][x]+a[x]-1)/a[x]);
        }
        cout<<*dsr.begin()<<"\n";
    }
    return 0;
}