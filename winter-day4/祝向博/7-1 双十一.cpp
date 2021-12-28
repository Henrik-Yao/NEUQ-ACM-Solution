#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

const int maxn = 105;
int lnk[maxn], tot, dis[maxn];
struct edge { int v, w, nxt; } e[maxn];

int N, M, Ans, Dis;

inline void add_edge(int w, int y, int x) {
	e[++tot] = { y,w,lnk[x] }, lnk[x] = tot;
	e[++tot] = { x,w,lnk[y] }, lnk[y] = tot;
}

bool vis[maxn];
struct node { int dis, x; };
inline bool operator <(node a, node b) { return a.dis > b.dis; }
priority_queue <node> Q;
void Calc(int st) {
	memset(dis, 0x7f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[st] = 0;
	Q.push({ 0,st });
	while (!Q.empty()) {
		node u = Q.top(); Q.pop();
		if (vis[u.x]) continue; vis[u.x] = 1;
		for (int k = lnk[u.x]; k; k = e[k].nxt) {
			if (dis[e[k].v] > dis[u.x] + e[k].w) {
				dis[e[k].v] = dis[u.x] + e[k].w;
				Q.push({ dis[e[k].v],e[k].v });
			}
		}
	}
	int tmp = 0;
	for (int i = 0; i < N; ++i) tmp += dis[i];
	if (tmp < Dis) Ans = st, Dis = tmp;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif

	while (~scanf("%d%d", &N, &M)) {
		tot = 0, Dis = 0x3f3f3f3f;
		for (int i = 0; i < N; ++i) lnk[i] = 0;
		for (int i = 1; i <= M; ++i) add_edge(read(), read(), read());
		for (int i = 0; i < N; ++i) Calc(i);
		printf("%d\n", Ans);
	}
	return 0;
}
