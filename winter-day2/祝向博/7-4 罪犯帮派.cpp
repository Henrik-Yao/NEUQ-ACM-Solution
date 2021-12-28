#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

const int maxn = 1e5 + 5;

int N, M, Q, fa[maxn], Ans;

int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif ONLINE_JUDGE
	N = read(), M = read(), Q = read();
	for (int i = 1; i <= N; ++i) fa[i] = i;
	for (int i = 1; i <= M; ++i) {
		int x = read(), y = read();
		fa[getfa(x)] = getfa(y);
	}
	for (int i = 1; i <= Q; ++i)
		puts(getfa(read()) == getfa(read()) ? "In the same gang." : "In different gangs.");
	for (int i = 1; i <= N; ++i) if (getfa(i) == i) ++Ans;
	printf("%d\n", Ans);
	return 0;
}
