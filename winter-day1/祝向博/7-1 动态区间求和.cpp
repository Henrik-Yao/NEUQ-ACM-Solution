#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6+5;

int N, Q, c[maxn];

inline int read() {
	int ret = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

void Add(int x, int ad) { for (; x <= N; x += x & -x) c[x] += ad; }

int Get(int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += c[x];
	return ret;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif // !ONLINE_JUDGE

	N = read(), Q = read();
	for (int i = 1; i <= N; ++i) Add(i, read());
	for (int i = 1; i <= Q; ++i) {
		int op = read(), l = read(), r = read();
		if (op == 1) Add(l, r);
		else printf("%lld\n", Get(r) - Get(l - 1));
	}
	return 0;
}
