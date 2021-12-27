#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

int T, N, Ans, a[5000];
vector <int> F;

void dfs(int x, int dep) {
	if (a[x] == 0) return;
	if (dep > Ans) Ans = dep;
	dfs(x * 2, dep + 1);
	F.push_back(a[x]);
	dfs(x * 2 + 1, dep + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	for (T = read(); T--; ) {
		N = read();
		F.clear();
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= N; ++i) a[i] = read();
		Ans = 1, dfs(1, 1);
		for (int i = 0; i < F.size() - 1; ++i)
			printf("%d ", F[i]);
		printf("%d\n%d\n", F[F.size() - 1], Ans);
	}
	return 0;
}
