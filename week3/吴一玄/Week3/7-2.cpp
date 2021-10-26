#include<bits/stdc++.h>
using namespace std;

int n, m, f[510], v[510];
vector<int> G[510];

int dfs(int x)
{
    v[x] = 1;
    if(f[x]) return f[x];
    for(auto y: G[x])
        f[x] += dfs(y);
    return f[x];
}

int main()
{
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    f[t] = 1;
    cout << dfs(s) << " ";
    int flag = 1;
    for(int i = 1; i <= n; ++i)
        if(!f[i] && v[i]) flag = 0;
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}    