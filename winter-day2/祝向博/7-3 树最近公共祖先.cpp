#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

const int maxn = 1e5 + 5;

int T, N, f[maxn][21], dep[maxn], w[maxn];
map <int, int> mp;

void dfs(int x, int d) {
	int r;
	while ((r = read()) != 0) {
		f[++N][0] = x;
		mp[r] = N, w[N] = r, dep[N] = d + 1;
		dfs(N, d + 1);
	}
}

void LCA_init() {
	for (int j = 1; (1 << j) <= N; ++j)
		for (int i = 1; i <= N; ++i)
			f[i][j] = f[f[i][j - 1]][j - 1];
}

int LCA(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	int d = dep[y] - dep[x];
	for (int i = 0; (1 << i) <= d; ++i) if (d & (1 << i)) y = f[y][i];
	if (x != y) {
		for (int i = (int)log2(N); i >= 0; --i)
			if (f[x][i] != f[y][i])
				x = f[x][i], y = f[y][i];
		x = f[x][0];
	}
	return x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif ONLINE_JUDGE
	for (T = read(); T--;) {
		mp.clear();
		int r = read();
		mp[r] = 1, w[1] = r, dep[1] = 1, f[1][0] = 0;
		N = 1, dfs(1, 1), read();
		LCA_init();
		printf("%d\n", w[LCA(mp[read()], mp[read()])]);
	}
	return 0;
}
