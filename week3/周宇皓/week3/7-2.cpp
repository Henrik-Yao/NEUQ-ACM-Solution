#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,head[605],cnt,st,ed,num[605];
bool flag=1;
struct node
{
    ll to,nex;
}edge[1000005];
ll dfs(ll now)
{
    if(num[now]) return num[now];
    ll res=0;
    for(ll i=head[now];i!=-1;i=edge[i].nex)
    {
        ll da=edge[i].to;
        res+=dfs(da);
    }
    if(res==0) flag=0;
    return num[now]=res;
}
int main()
{
    cin>>n>>m;
    memset(head,-1,sizeof head);
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        edge[++cnt].to=v;
        edge[cnt].nex=head[u];
        head[u]=cnt;
    }
    cin>>st>>ed;
    num[ed]=1;
    cout<<dfs(st)<<' ';
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
