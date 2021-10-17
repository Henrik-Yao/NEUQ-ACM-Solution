#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 10010;

int n, m, a[MAXN], v[MAXN];
vector<int> G[MAXN];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int Q; scanf("%d", &Q);
    while(Q--)
    {
        int k; scanf("%d", &k);
        memset(v, 0, sizeof(v));
        for(int i = 1; i <= k; ++i)
        {
            int x; scanf("%d", &x);
            v[x] = 1;
        }
        int flag = 1;
        for(int i = 1; i <= n; ++i)
            if(!v[i])
            {
                for(auto y: G[i])
                    if(!v[y]) {flag = 0; break;}
                if(!flag) break;
            }
        if(!flag) puts("NO");
        else puts("YES");
    }
    return 0;
}