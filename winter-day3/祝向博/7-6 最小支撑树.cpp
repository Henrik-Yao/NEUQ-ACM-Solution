#include <bits/stdc++.h>
using namespace std;
const int maxn = 1505;
int N, M, Ans, fa[maxn];
inline int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
struct edge { int x, y, z; } a[maxn];
inline bool operator <(edge a, edge b) { return a.z < b.z; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif

	while (~scanf("%d%d", &N, &M)) {
		for (int i = 1; i <= N; ++i) fa[i] = i;
		for (int i = 1; i <= M; ++i)
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		sort(a + 1, a + 1 + M);
		Ans = 0;
		for (int i = 1; i <= M; ++i)
			if (getfa(a[i].x) != getfa(a[i].y)) {
				Ans += a[i].z, --N;
				fa[getfa(a[i].x)] = getfa(a[i].y);
			}
		if (N == 1) printf("%d\n", Ans);
		else puts("There is no minimum spanning tree.");
	}
	return 0;
}
