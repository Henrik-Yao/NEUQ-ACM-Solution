#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int v[20010];
vector<int> Vec[20010], ans;

void dfs(int x)
{
    v[x] = 1;
    ans.push_back(x);
    for(auto y: Vec[x])
    {
        if(v[y]) continue;
        dfs(y);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        cin>>u>>v;
        Vec[u].push_back(v);
    }
    for(int i = 0; i < n; ++i)
    {
        sort(Vec[i].begin(), Vec[i].end());
    }
    for(int i = 0; i < n; ++i)
    {
        if(!v[i])
        {
            dfs(i);
        }
    }
    for(int i = 0; i < ans.size(); ++i)
    {
        cout<<ans[i]<<" ";
    }
        
    return 0;
}