#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 100010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, fa[MAXN];
struct Edge
{
    int u, v, w;
    bool operator < (const Edge &x) const
    {
        return w < x.w;
    }
}e[MAXN];

inline int get(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}

int main()
{
    in(n, m);
    for(int i = 1; i <= m; ++i) in(e[i].u, e[i].v, e[i].w);
    for(int i = 1; i <= n; ++i) fa[i] = i;
    sort(e + 1 , e + 1 + m);
    ll sum = 0;
    for(int i = 1; i <= m; ++i)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(get(u) == get(v)) continue;
        sum = max(sum, (ll)w);
        fa[get(u)] = get(v);
    }
    cout << n - 1 << " " << sum << "\n";
    return 0;
}