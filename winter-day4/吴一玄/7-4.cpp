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

struct Node
{
    int u; ll dis;
    bool operator < (const Node &x) const
    {
        return dis > x.dis;
    }
};

vector< pair<int, ll> > G[MAXN];
ll dis[MAXN]; int path[MAXN];

void dijkstra(int s)
{
    memset(path, 0, sizeof(path));
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<Node> q;
    q.push((Node){s, 0}); dis[s] = 0;
    while(!q.empty())
    {
        Node x = q.top(); q.pop();
        if(dis[x.u] != x.dis) continue;
        for(auto y: G[x.u])
            if(dis[y.first] > dis[x.u] + y.second)
            {
                dis[y.first] = dis[x.u] + y.second;
                q.push((Node){y.first, dis[y.first]});
                path[y.first] = x.u;
            }
    }
}

void Print(int x, int t)
{
    if(!x) return;
    Print(path[x], t);
    if(x != t) cout << x - 1 << "->";
    else cout << x - 1 << ":";
}

void solve(int s, int t)
{
    ++s, ++t;
    if(s == t)
    {
        cout << s - 1 << "->" << t - 1 << ":0\n";
        return;
    }
    dijkstra(s);
    if(dis[t] == 0x3f3f3f3f3f3f3f3f)
    {
        cout << s - 1 << "->" << t - 1 << ":-1\n";
        return;
    }
    Print(t, t);
    cout << dis[t] << "\n";
}

int main()
{
    int n, m;
    in(n, m);
    while(m--)
    {
        int u, v; ll w;
        in(u, v, w); ++u, ++v;
        G[u].push_back(make_pair(v, w));
    }
    int s, t;
    in(s, t); solve(s, t);
    in(s, t); solve(s, t);
    ll mx = 0; s = t = 0;
    for(int i = 1; i <= n; ++i)
    {
        dijkstra(i);
        for(int j = 1; j <= n; ++j)
        {
            if(dis[j] == 0x3f3f3f3f3f3f3f3f) continue;
            if(dis[j] > mx)
            {
                mx = dis[j];
                s = i, t = j;
            }
        }
    }
    solve(s - 1, t - 1);
    return 0;    
}