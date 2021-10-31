#include<bits/stdc++.h>
using namespace std;

int n, m, k, flag;
vector<int> G[110];
bool safe[110], v[110];

void dfs(int x)
{
    v[x] = 1;
    for(auto y: G[x])
    {
        if(v[y] || !safe[y]) continue;
        dfs(y);
    }
}

int main()
{
    cin >> m >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        safe[x] = 1;
    }
    while(k--)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s, t;
    cin >> s >> t;
    if(!safe[t]) {printf("The city %d is not safe!\n", t); return 0;}
    dfs(s);
    if(v[t]) printf("The city %d can arrive safely!\n", t);
    else printf("The city %d can not arrive safely!\n", t);
    return 0;
}