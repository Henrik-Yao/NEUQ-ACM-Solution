#include <bits/stdc++.h>
using namespace std;
const int maxn = 1505;

bool flg;
int N, M, sum, in[maxn];
int lnk[maxn], tot;
struct edge { int v, nxt; } e[maxn];
queue <int> Q;

inline void add_edge(int x, int y) {
	++in[y];
	e[++tot] = { y,lnk[x] }, lnk[x] = tot;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	while (~scanf("%d%d", &N, &M)) {
		tot = 0;
		for (int i = 1; i <= N; ++i) lnk[i] = 0;
		for (int i = 1; i <= M; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			add_edge(x, y);
		}
		flg = 0, sum = 0;
		for (int i = 1; i <= N; ++i) if (in[i] == 0) Q.push(i), ++sum;
		while (!Q.empty()) {
			int tp = Q.front(); Q.pop();
			if (!Q.empty()) flg = 1;
			for (int k = lnk[tp]; k; k = e[k].nxt) {
				--in[e[k].v];
				if (in[e[k].v] == 0) Q.push(e[k].v), ++sum;
			}
		}
		if (sum < N) puts("0");
		else puts(flg ? "2" : "1");
	}
	return 0;
}
