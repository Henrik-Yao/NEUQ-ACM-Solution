#include<bits/stdc++.h>
using namespace std;
vector<int> v[20010];
bool vis[20010];
int n,m;
void dfs(int now)
{
    if(vis[now])
    return ;
    vis[now]=1;
    cout<<now<<" ";
    for(int i=0;i<v[now].size();i++)
    dfs(v[now][i]);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=0;i<n;i++)
    {
        if(v[i].size()>1)
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }
    return 0;
}
