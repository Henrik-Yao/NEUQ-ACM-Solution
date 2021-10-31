#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,k,cnt,sta,en;
bool saf[109];
vector<ll> vv[105];
bool vis[105];
bool flag=0;
void dfs(ll now)
{
    if(flag)
    return ;
    if(now==en)
    {
        flag=1;
        return ;
    }
    for(int i=0;i<vv[now].size();i++)
    {
        int da=vv[now][i];
        if(!vis[da]&&saf[da])
        {
            vis[da]=1;
            dfs(da);
            vis[da]=0;
        }
    }
}
int main()
{
    cin>>m>>n>>k;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        saf[x]=1;
    }
    for(ll i=0;i<k;i++)
    {
        ll u,v;
        cin>>u>>v;
        vv[u].push_back(v);
        vv[v].push_back(u);
    }
    cin>>sta>>en;
    if(saf[en]==0)
    {
        printf("The city %lld is not safe!",en);
    }
    else 
    {
        vis[sta]=1;
        dfs(sta);
        if(flag)
        printf("The city %d can arrive safely!",en);
        else 
        printf("The city %d can not arrive safely!",en);
    }
    return 0;
}
