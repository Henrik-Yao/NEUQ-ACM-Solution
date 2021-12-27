
#include <bits/stdc++.h>
#define ll long long
#define maxn 100011
using namespace std;

inline ll read()
{
    ll res, op = 1;
    char ch;
    while ((ch = getchar()) < '0' || ch > '9')
        if (ch == '-')
            op = -1;
    res = (ll)(ch - '0');
    while ((ch = getchar()) <= '9' && ch >= '0')
        res = (res << 1) + (res << 3) + (ll)(ch - '0');
    return res * op;
}

int n, m, dep;
ll tr[9999];
bool isfirst = true;
void dfs(int x, int dept)
{
    if (x > n)
        return;
    if(!tr[x]) return;
    
    dfs(x << 1, dept + 1);
    dep = max(dept, dep);
    
    if(isfirst) {printf("%lld", tr[x]);isfirst = false;}
    else printf(" %lld", tr[x]);
    dfs(x << 1 | 1, dept + 1);
}
void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        tr[i] = read();
    dep = 0;
    isfirst = true;
    dfs(1, 1);
    printf("\n");
    printf("%d\n", dep);
}
ll tt;
int main()
{
    // ios::sync_with_stdio(0);cin.tie(0);
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}

