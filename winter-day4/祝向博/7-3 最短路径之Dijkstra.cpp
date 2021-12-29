#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

const int maxn = 5e5 + 5;
int lnk[maxn], tot, dis[maxn], lst[maxn];
struct edge { int v, w, nxt; } e[maxn];

int N, M, U, V;

inline void add_edge(int w, int y, int x) {
	//printf("%d->%d\n", x, y);
	e[++tot] = { y,w,lnk[x] }, lnk[x] = tot;
	e[++tot] = { x,w,lnk[y] }, lnk[y] = tot;
}

bool vis[maxn];
struct node { int dis, x; };
inline bool operator <(node a, node b) { return a.dis > b.dis; }
priority_queue <node> Q;

void write(int x) {
	if (x == U) {
		if (x != V) return void(printf("%d", U));
		else return void(printf("%d-->%d:0", U, U));
	}
	write(lst[x]);
	printf("-->%d", x);
	if (x == V) printf(":%d", dis[V]);
}

void Calc(int st) {
	memset(dis, 0x7f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[st] = 0;
	Q.push({ 0,st });
	while (!Q.empty()) {
		node u = Q.top(); Q.pop();
		if (vis[u.x]) continue; vis[u.x] = 1;
		//printf("u=%d dis=%d \n", u.x, dis[u.x]);
		for (int k = lnk[u.x]; k; k = e[k].nxt) {
			if (dis[e[k].v] > dis[u.x] + e[k].w) {
				dis[e[k].v] = dis[u.x] + e[k].w;
				lst[e[k].v] = u.x;
				//printf("\tv=%d dis=%d\n", e[k].v, dis[e[k].v]);
				Q.push({ dis[e[k].v],e[k].v });
			}
		}
	}
	write(V = read());
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	N = read(), M = read() / 2;
	tot = 0; for (int i = 0; i < N; ++i) lnk[i] = 0;
	for (int i = 1; i <= M; ++i) add_edge(read(), read(), read());
	Calc(U = read());
	return 0;
}
