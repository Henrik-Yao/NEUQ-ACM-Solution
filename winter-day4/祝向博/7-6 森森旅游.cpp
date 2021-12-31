#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}
const int maxn = 1e5 + 5;
const long long INF = 0x7f7f7f7f7f7f7f7f;
int N, M, Qu, a[maxn];
int lnk[2][maxn], tot, vis[maxn];
long long dis[2][maxn];
struct edge { int v, nxt, w; } e[2][maxn * 2];

inline void add_edge(int d, int c, int y, int x) {
	if (x == y) return;
	e[0][++tot] = { y,lnk[0][x],c }, lnk[0][x] = tot;
	e[1][tot] = { x,lnk[1][y],d }, lnk[1][y] = tot;
}

struct Node { long long dis; int x; };
inline bool operator <(Node a, Node b) { return a.dis > b.dis; }
priority_queue <Node> Q; //默认大根堆
void Dij(int st, int f) {
	memset(vis, 0, sizeof vis);
	memset(dis[f], 0x7f, sizeof dis[f]);
	dis[f][st] = 0;
	Q.push({ 0,st });
	while (!Q.empty()) {
		Node tp = Q.top(); Q.pop();
		if (vis[tp.x]) continue;
		vis[tp.x] = 1;
		for (int k = lnk[f][tp.x]; k; k = e[f][k].nxt) {
			int& v = e[f][k].v;
			if (dis[f][v] > dis[f][tp.x] + e[f][k].w) {
				dis[f][v] = dis[f][tp.x] + e[f][k].w;
				Q.push({ dis[f][v],v });
			}
		}
	}
}
struct node { double x; int id, a; };
inline bool operator <(node a, node b) { return a.x > b.x; }
signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	N = read(), M = read(), Qu = read();
	for (int i = 1; i <= M; ++i)
		add_edge(read(), read(), read(), read());
	Dij(1, 0), Dij(N, 1);
	priority_queue <node> q;
	for (int i = 1; i <= N; ++i) {
		a[i] = read();
		if (dis[0][i] != INF && dis[1][i] != INF)
			q.push({ dis[0][i] + 1.0 * dis[1][i] / a[i], i, a[i] });
	}
	for (int i = 1; i <= Qu; ++i) {
		int pos = read(); a[pos] = read();
		if (dis[0][pos] != INF && dis[1][pos] != INF)
			q.push({ dis[0][pos] + 1.0 * dis[1][pos] / a[pos], pos, a[pos] });
		while (a[q.top().id] != q.top().a) q.pop();
		printf("%lld\n", (long long)(ceil(q.top().x)));
	}
	return 0;
}
