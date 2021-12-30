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

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m;
int a[110][110];

int get(int x, int y)
{
    return (x - 1) * m + y;
}

void reget(int id, int &x, int &y)
{
    y = id % m;
    x = (id - y) / m + 1;
}

vector< pair<int, int> > ans;

void Print(int x)
{
    if(!x) return;
    Print(path[x]);
    int xx, yy;
    reget(x, xx, yy);
    ans.push_back(make_pair(xx - 1, yy - 1));
}

int main()
{
    in(n, m);
    int s, t, xx, yy;
    in(xx, yy); ++xx; ++yy; s = get(xx, yy);
    in(xx, yy); ++xx; ++yy; t = get(xx, yy);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) in(a[i][j]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int d = 3; d >= 0; --d)
            {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                ll cost = 0;
                if(a[nx][ny] == -1) cost = 0x3f3f3f3f;
                else cost = a[nx][ny];
                G[get(i, j)].push_back(make_pair(get(nx, ny), cost));
            }
    dijkstra(s);
    Print(t);
    reverse(ans.begin(), ans.end());
    for(auto x: ans) cout << "(" << x.first << " " << x.second << ")";
    return 0;
}