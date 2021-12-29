#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10,inf=1e18;
ll n,m,q,head[N],cnt,dis1[N],dis2[N],val[N],vis[N];
ll h[N],cnt1;
struct Edge
{
    ll to,nex,dis1,dis2;
}edge[2*N];
struct Edg
{
    ll to,nex,dis2;
}e[2*N];
void add(int a,int b,int c,int d)
{
    edge[++cnt].to=b;
    edge[cnt].dis1=c;
    edge[cnt].nex=head[a];
    head[a]=cnt;
}
void add(int a,int b,int c)
{
    e[++cnt1].to=b;
    e[cnt1].dis2=c;
    e[cnt1].nex=h[a];
    h[a]=cnt1;
}
struct node
{
    ll now,dis;
    friend bool operator<(const node&a,const node&b)
    {
        return a.dis>b.dis;
    }
};
void dij1()
{
    for(ll i=0;i<=n;i++) dis1[i]=inf;
    dis1[1]=0;
    priority_queue<node> q;
    q.push({1,0});
    memset(vis,0,sizeof vis);
    while (!q.empty())
    {
        node a=q.top();
        q.pop();
        if(vis[a.now]) continue;
        vis[a.now]=1;
        for(ll i=head[a.now];i!=-1;i=edge[i].nex)
        {
            ll j=edge[i].to;
            if(dis1[j]>dis1[a.now]+edge[i].dis1)
            {
                dis1[j]=dis1[a.now]+edge[i].dis1;
                q.push({j,dis1[j]});
            }
        }
    }
}
void dij2()
{
    for(ll i=0;i<=n;i++) dis2[i]=inf;
    dis2[n]=0;
    priority_queue<node> q;
    q.push({n,0});
    memset(vis,0,sizeof vis);
    while (!q.empty())
    {
        node a=q.top();
        q.pop();
        if(vis[a.now]) continue;
        vis[a.now]=1;
        for(ll i=h[a.now];i!=-1;i=e[i].nex)
        {
            ll j=e[i].to;
            if(dis2[j]>dis2[a.now]+e[i].dis2)
            {
                dis2[j]=dis2[a.now]+e[i].dis2;
                q.push({j,dis2[j]});
            }
        }
    }
}
ll up(ll shan,ll xia)
{
    return (shan+xia-1)/xia;
}
int main()
{
    memset(h,-1,sizeof h);
    memset(head,-1,sizeof head);
    cin>>n>>m>>q;
    for(ll i=0;i<m;i++)
    {
        ll a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        add(a,b,c,d);
        add(b,a,d);
    }
    for(ll i=1;i<=n;i++) scanf("%lld",&val[i]);
    dij1();
    dij2();
    multiset<ll> s;
    for(int i = 1;i <= n; i ++ ){
    //必须要可以连通
        if(dis1[i] != inf && dis2[i] != inf){
        //此时对于后面需要的代金券兑换的现金需要向上取整,所以要加radio[i]-1
           s.insert(dis1[i]+(dis2[i]+val[i]-1)/val[i]);
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        if(dis1[a]!=inf && dis2[a] !=inf){
        s.erase(s.find(dis1[a]+(dis2[a]+val[a]-1)/val[a]));
        val[a] = b;
        s.insert(dis1[a]+(dis2[a]+val[a]-1)/val[a]);
        }
        cout << *s.begin()<<endl;
    }
    return 0;
}
