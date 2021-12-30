#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 100010;
const ll inf = 0x3f3f3f3f3f3f3f3f;

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

vector< pair<int, ll> > G[2][MAXN];
ll dis[2][MAXN];

void dijkstra(int s, int id)
{
    memset(dis[id], 0x3f, sizeof(dis[id]));
    priority_queue<Node> q;
    q.push((Node){s, 0}); dis[id][s] = 0;
    while(!q.empty())
    {
        Node x = q.top(); q.pop();
        if(dis[id][x.u] != x.dis) continue;
        for(auto y: G[id][x.u])
            if(dis[id][y.first] > dis[id][x.u] + y.second)
            {
                dis[id][y.first] = dis[id][x.u] + y.second;
                q.push((Node){y.first, dis[id][y.first]});
            }
    }
}

int n, m, q;
ll cost[MAXN];

multiset<ll> S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    in(n, m, q);
    for(int i = 1; i <= m; ++i)
    {
        int u, v; ll c, d;
        in(u, v, c, d);
        G[0][u].push_back(make_pair(v, c));
        G[1][v].push_back(make_pair(u, d));
    }
    dijkstra(1, 0);
    dijkstra(n, 1);
    for(int i = 1; i <= n; ++i)
    {
        in(cost[i]);
        if(dis[0][i] != inf && dis[1][i] != inf)
            S.insert(dis[0][i] + (dis[1][i] + cost[i] - 1ll) / cost[i]);
    }
    while(q--)
    {
        int u; ll v;
        in(u, v);
        if(dis[0][u] != inf && dis[1][u] != inf)
        {
            auto it = S.find(dis[0][u] + (dis[1][u] + cost[u] - 1ll) / cost[u]);
            S.erase(it);
            cost[u] = v;
            S.insert(dis[0][u] + (dis[1][u] + cost[u] - 1ll) / cost[u]);
        }
        cout << *S.begin() << "\n";
    }
    return 0;
}