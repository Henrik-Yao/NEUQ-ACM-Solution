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
    if(x != t) cout << x - 1 << "-->";
    else cout << x - 1 << ":";
}

int main()
{
    int n, m;
    in(n, m); m >>= 1;
    while(m--)
    {
        int u, v; ll w;
        in(u, v, w); ++u, ++v;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    int s, t; in(s, t); ++s, ++t;
    if(s == t)
    {
        cout << s - 1 << "-->" << t - 1 << ":0\n";
        return 0;
    }
    dijkstra(s);
    Print(t, t);
    cout << dis[t] << "\n";
    return 0;    
}