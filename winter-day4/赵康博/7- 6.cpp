#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>

#define y second

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int N = 100010, M = 200010 * 2;
const ll inf = 0x3f3f3f3f3f3f3f3fll;

int n, m, q;
int h1[N], h2[N], e[M], ne[M], w[M], idx;
bool st[N];
int a[N];
ll d1[N], d2[N];

void add(int h[], int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dijkstra(int h[], ll dis[], int start)
{
    memset(dis, 0x3f, sizeof d1);
    memset(st, false, sizeof st);
    priority_queue<P, vector<P>, greater<P> > heap;
    heap.push({0, start});
    dis[start] = 0;
    
    while(heap.size())
    {
        P t = heap.top();
        heap.pop();
        
        int u = t.y;
        if(st[u]) continue;
        st[u] = true;
        
        for(int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dis[j] > dis[u] + w[i])
            {
                dis[j] = dis[u] + w[i];
                heap.push({dis[j], j});
            }
        }
    }
}

int main()
{
    memset(h1, -1, sizeof h1);
    memset(h2, -1, sizeof h2);
    cin>>n>>m>>q;
    
    int u, v, c, d;
    while(m --)
    {
        cin>>u>>v>>c>>d;
        add(h1, u, v, c), add(h2, v, u, d);
    }
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    
    dijkstra(h1, d1, 1), dijkstra(h2, d2, n);
    
    multiset<ll> S;
    for(int i = 1; i <= n; i ++)
        if(d1[i] != inf && d2[i] != inf)
            S.insert(d1[i] + (d2[i] + a[i] - 1) / a[i]);
        
    while(q --)
    {
        cin>>u>>v;
        auto pos = S.find(d1[u] + (d2[u] + a[u] - 1) / a[u]);
        if(pos != S.end())
        {
            S.erase(pos);
            S.insert(d1[u] + (d2[u] + v - 1) / v);
            a[u] = v;
        }
        printf("%lld\n", *S.begin());
    }
    
    return 0;
}
