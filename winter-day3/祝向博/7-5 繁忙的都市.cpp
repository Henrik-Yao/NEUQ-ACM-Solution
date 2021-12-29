#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}
const int maxn = 5e5 + 5;
int N, M, mx, fa[maxn];
inline int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
struct edge { int x, y, z; } a[maxn];
inline bool operator <(edge a, edge b) { return a.z < b.z; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	N = read(), M = read();
	for (int i = 1; i <= N; ++i) fa[i] = i;
	for (int i = 1; i <= M; ++i)
		a[i].x = read(), a[i].y = read(), a[i].z = read();
	sort(a + 1, a + 1 + M);
	for (int i=1; i<=M; ++i)
		if (getfa(a[i].x) != getfa(a[i].y)) {
			mx = a[i].z;
			fa[getfa(a[i].x)] = getfa(a[i].y);
		}
	printf("%d %d", N - 1, mx);
	return 0;
}
