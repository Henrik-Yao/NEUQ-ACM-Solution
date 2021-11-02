#include <bits/stdc++.h>
using namespace std;
int bj[505][505];
int lu[505];
int visit[505];
int n;
int dfs(int x)
{
    visit[x]=1;
    if(lu[x])
    return lu[x];
    for(int i=1;i<=n;i++)
    {
        if(bj[x][i])
        lu[x]+=dfs(i);
    }
    return lu[x];
}
int main()
{
    int m;
    cin>>n>>m;
    memset(bj,0,sizeof(bj));
    memset(lu,0,sizeof(lu));
    memset(visit,0,sizeof(visit));
    int a,b;
    int i;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        bj[a][b]=1;
    }
    int x,y;
    cin>>x>>y;
    lu[y]=1;
    dfs(x);
    cout<<lu[x]<<" ";
    int f=1;
    for(i=1;i<=n;i++)
    {
        if(visit[i]&&!lu[i])
        {
            f=0;
            break;
        }
    }
    if(f)cout<<"Yes\n";
    else 
    cout<<"No\n";
    return 0;
}
