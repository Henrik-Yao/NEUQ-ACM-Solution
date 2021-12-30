#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PII;
const int N = 100010, M = 200010 * 2;
const LL INF = 0x3f3f3f3f3f3f3f3fll;
int n, m, Q;
int h1[N], h2[N], e[M], w[M], ne[M], idx;
LL dist1[N], dist2[N];
bool st[N];
int ratio1[N];
// 添加一条边 a->b边权为c
void add(int h[], int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dijkstra(int h[], LL dist[], int start) {
    memset(dist, 0x3f, sizeof dist1);
    memset(st, false, sizeof st);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> Q;
    memset(h1, -1, sizeof h1);
    memset(h2, -1, sizeof h2);
    while (m--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add(h1, a, b, c), add(h2, b, a, d);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &ratio1[i]);
    dijkstra(h1, dist1, 1);
    dijkstra(h2, dist2, n);
    multiset<LL> S;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] != INF && dist2[i] != INF) {
            S.insert(dist1[i] + (dist2[i] + ratio1[i] - 1) / ratio1[i]);
        }
    }
    while (Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (dist1[a] != INF && dist2[a] != INF) {
            S.erase(S.find(dist1[a] + (dist2[a] + ratio1[a] - 1) / ratio1[a]));
            ratio1[a] = b;
            S.insert(dist1[a] + (dist2[a] + ratio1[a] - 1) / ratio1[a]);
        }
        printf("%lld\n", *S.begin());
    }
    return 0;
}