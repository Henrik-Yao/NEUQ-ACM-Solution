#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cash1[100002],    voucher1[100002],   rate[100002];
bool visit1[100002],visit2[100002];
ll c,d,money,sum[100002];
int n,m,q,u,v;
struct node
{
    int name;
    ll dis;
    friend bool operator < (const node &a,const node &b)
    {
        return (a.dis>b.dis);
    }
};
vector<pair<int,ll>>cash2[100002],voucher2[100002];    
multiset<ll>cost;
priority_queue<node>Q;   
void Dij(int t,vector<pair<int,ll>>a[],ll dis[],bool visit[]);
int main()
{
    cin>>n>>m>>q;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>c>>d;            
        cash2[u].push_back({v,c});          
        voucher2[v].push_back({u,d});
    }
    for(int i=1;i<=n;i++) cin>>rate[i];

memset(visit2,0,sizeof(visit2));
    memset(cash1,0x3f,sizeof(cash1));
    memset(voucher1,0x3f,sizeof(voucher1));
    memset(visit1,0,sizeof(visit1));
    

    Dij(1,cash2,cash1,visit1);      
    Dij(n,voucher2,voucher1,visit2);

    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
    {
        if(cash1[i]==cash1[100001] || voucher1[i]==voucher1[100001])
            continue;
        sum[i]=cash1[i]+(voucher1[i]+rate[i]-1)/rate[i];
        cost.insert(sum[i]);
    }

    int city,change;
    for(int i=0;i<q;i++)
    {
        cin>>city>>change;
        if(sum[city]==0 || rate[city]==change)
            cout<<*cost.begin()<<"\n";
        else
        {
            cost.erase(cost.find(sum[city]));
            rate[city]=change;
            sum[city]=cash1[city]+(voucher1[city]+rate[city]-1)/rate[city];
            cost.insert(sum[city]);
            cout<<*cost.begin()<<"\n";
        }
    }
    return 0;
}

void Dij(int t,vector<pair<int,ll>>a[],ll dis[],bool visit[])
{                   
    dis[t]=0;
    Q.push(node{t,0});
    while(!Q.empty())
    {
        int now=Q.top().name;
        Q.pop();
        if(visit[now]==1) continue;
        visit[now]=1;
        for(int i=0;i<a[now].size();i++)
        {
            v=a[now][i].first;
            money=a[now][i].second;
            if(dis[v]>dis[now]+money)
            {
                dis[v]=dis[now]+money;
                Q.push(node{v,dis[v]});
            }
        }
    }
}

