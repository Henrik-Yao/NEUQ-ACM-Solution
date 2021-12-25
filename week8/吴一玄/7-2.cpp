#include<bits/stdc++.h>
using namespace std;

inline char Getchar()
{
    static char buf[1000010], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

void in() {}
template<typename T, typename... otr_T>
void in(T &x, otr_T &...Ar)
{
    x = 0; int f = 1; char s = Getchar();
    for(; !isdigit(s); s = Getchar()) if(s == '-') f = 0;
    for(; isdigit(s); s = Getchar()) x = (x << 3) + (x << 1) + s - 48;
    x = (f ? x : -x);
    in(Ar...);
}

/*
#define ls (o << 1)
#define rs (o << 1 | 1)
const int MAXN = 4000010;
const int MAXM = 20000010;

struct Node
{
    int u, d;
    bool operator < (const Node &x) const
    {
        return d > x.d;
    }
};

int tot, dis[MAXN], Head[MAXN];
int ver[MAXM], Next[MAXM], edge[MAXM];

inline void add(int u, int v, int z)
{
    ver[++tot] = v;
    Next[tot] = Head[u];
    Head[u] = tot;
    edge[tot] = z;
}

void dijkstra(int s)
{
    priority_queue<Node> Q;
    memset(dis, 0x3f, sizeof(dis));
    Q.push((Node){s, 0}); dis[s] = 0;
    while(!Q.empty())
    {
        Node x = Q.top(); Q.pop();
        if(dis[x.u] != x.d) continue;
        for(register int i = Head[x.u]; i; i = Next[i])
        {
            register int y = ver[i], z = edge[i];
            if(dis[y] > dis[x.u] + z)
            {
                dis[y] = dis[x.u] + z;
                Q.push((Node){y, dis[y]});
            }
        }
    }
}

int mx, id[MAXN];
void Build(int o, int l, int r)
{
    mx = max(mx, o);
    if(l == r)
    {
        id[l] = o;
        return;
    }
    int mid = (l + r) >> 1;
    Build(ls, l, mid);
    Build(rs, mid + 1, r);
    add(o, ls, 0);
    add(o, rs, 0);
}

void adds(int o, int l, int r, int L, int R, int s)
{
    if(L <= l && r <= R)
    {
        add(s, o, 1);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) adds(ls, l, mid, L, R, s);
    if(R > mid) adds(rs, mid + 1, r, L, R, s);
}

void solve()
{
    int n; in(n);
    Build(1, 1, n);
    for(register int i = 1; i <= n; ++i)
    {
        int x; in(x);
        int l = (i - x) < 1 ? 1 : i - x;
        int r = (i + x) > n ? n : i + x;
        adds(1, 1, n, l, r, id[i]);
    }
    dijkstra(id[1]);
    printf("%d\n", dis[id[n]]);
}
*/

int n, a[1000010];

int main()
{
    in(n);
    for(int i = 1; i <= n; ++i) in(a[i]);
    int ans = 0, s = 1;
    while(s < n)
    {
        int t = s + a[s];
        if(t >= n) {++ans; break;}
        int mx = 0, pos = 0;
        for(int i = s + 1; i <= t; ++i)
            if(a[i] + i > mx) mx = a[i] + i, pos = i;
        ++ans; s = pos;
    }
    printf("%d\n", ans);
    return 0;
}