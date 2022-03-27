#include<bits/stdc++.h>
using namespace std;

int v[20010];
vector<int> G[20010], ans;

void dfs(int x)
{
    v[x] = 1;
    ans.push_back(x);
    for(auto y: G[x])
    {
        if(v[y]) continue;
        dfs(y);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    for(int i = 0; i < n; ++i)
        sort(G[i].begin(), G[i].end());
    for(int i = 0; i < n; ++i)
        if(!v[i]) dfs(i);
    for(int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    return 0;
}