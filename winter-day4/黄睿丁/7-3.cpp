#include <bits/stdc++.h>
using namespace std;
struct node{
    int v;
    int w;
};
int n,e;
vector<node>p[1001];
int dist[1001],vis[1001],path[1001];
void Dijkstra(int sta)
{
    memset(dist,1000000009,sizeof(dist));
    dist[sta]=0;
    for(int i=0;i<n;i++)
    {
        int u =1,minm=1000000009;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&dist[j]<minm)
            {
                minm=dist[j];
                u=j;
            }
        }
        if(u==-1)
            break;
        vis[u]=1;
        for(int j=0,sz=p[u].size();j<sz;j++)
        {
            int x=p[u][j].v;
            if(!vis[x]&&dist[x]>dist[u]+p[u][j].w)
            {
                dist[x]=dist[u]+p[u][j].w;
                path[x]=u;
            }
        }
    }
}
int main(){
    cin>>n>>e;
    for(int i=0;i<e/2;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        p[a].push_back(node{b,c});
        p[b].push_back(node{a,c});
    }
    int sta,end;
    cin>>sta>>end;
    if(sta==end)
    {
        printf("%d-->%d:0",sta,end);
        return 0;
    }
    Dijkstra(sta);
    vector<int>ans;
    int x=end;
    while(x!=sta)
    {
        ans.push_back(x);
        x=path[x];
    }
    cout<<sta;
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<"-->"<<ans[i];
    }
    printf(":%d",dist[end]);
    return 0;
}
